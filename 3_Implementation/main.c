#include <avr/io.h>
#include <util/delay.h>
#include <lcd.h>
#include <avr/interrupt.h>
#include <math.h>


#define KEYPAD D
#define KEYPAD_PORT PORT(KEYPAD)
#define KEYPAD_DDR   DDR(KEYPAD)
#define KEYPAD_PIN   PIN(KEYPAD)


unsigned int failedAttempts;


/////////////////////////////   EEPROM INITILIZE  AND CONFIGURATION   ///////////////////////////////////////////////////////////////


void EEPROM_write(unsigned int address, unsigned char data){
cli();

/* Wait for completion of previous write */
while(EECR & (1<<EEPE));

/* Set up address and Data Registers */
EEAR = address;
EEDR = data;

/* Write logical one to EEMPE */
EECR |= (1<<EEMPE);

/* Start eeprom write by setting EEPE */
EECR |= (1<<EEPE);

sei();

}


char EEPROM_read(unsigned int address){
cli();

/* Wait for completion of previous write */
while(EECR & (1<<EEPE));

/* Set up address register */
EEAR = address;

/* Start eeprom read by writing EERE */
EECR |= (1<<EERE);

sei();

/* Return data from Data Register */
return EEDR;

}



unsigned int readEEPROM(int pos){

           return ((EEPROM_read(pos + 1)*100)+EEPROM_read(pos));
            }
                       
                       
                       
void writeEEPROM(unsigned int pos, unsigned int val){

		volatile unsigned int a=val%100;         //last two digit of the paaword
		volatile unsigned int b=val/100;        //first two digit of the password
                                                  
                                  
                        EEPROM_write(pos, a);
                        EEPROM_write(pos + 1, b);
               
        }    

   
unsigned int validate_password(unsigned int enterd_password){

       unsigned int EEPROM_pos=0;
          
       while(EEPROM_pos<20){
		
			if(readEEPROM(EEPROM_pos)==enterd_password){
					return 1;
				}
				
			EEPROM_pos+=2;
		}
		
		return 0;
	}	
 

//////////////////////////////   KEYPAD INTERFACING      /////////////////////////////////////////////////


unsigned int GetKeyPressed()
{
      uint8_t r,c;

      KEYPAD_PORT|= 0X0F;
         

      for(c=0;c<4;c++)
      {
         KEYPAD_DDR&=~(0XFF);

         KEYPAD_DDR|=(0X80>>c);
         for(r=0;r<4;r++)
         {
            if(!(KEYPAD_PIN & (0X08>>r)))
            {
               return (r*3+c);
            }
         }
      }
          return 0XFF;//Indicate No key pressed
}


unsigned int calcPass(unsigned int key,unsigned int position, unsigned int currentVal){
    unsigned multi =0;
      
        if(position ==0)
                multi=1000;
        else if(position ==1)
                multi=100;
        else if(position ==2)
                multi=10;
        else if(position ==3)
                multi=1;
       
                return currentVal+key*multi;
       
}


unsigned int Getpassword(){

unsigned int key;
unsigned int password = 0;
unsigned int position = 0;

start:
LCDClear();


while(position < 4){

	while(GetKeyPressed()!=255){
		key=GetKeyPressed();
		
			if(key<10){

				password=calcPass(key,position, password);
               
				LCDWriteStringXY(position,0,"*");

				position++;
				_delay_ms(50);

			}
			
			else if(key==10){
			
			goto start;
			}

		}
	}

return password;
}
  

unsigned int Getuserid(){

	   volatile unsigned int userid = 0;
       volatile unsigned int position = 0;
	   volatile unsigned int currentval = 0;
	   volatile unsigned int multi;
	   start:
       LCDClear();
       while(position < 2){       
               if(GetKeyPressed()<10){
                       currentval  = GetKeyPressed();
					   if((position == 0) && (currentval>1)){
							userid = currentval;
							LCDWriteIntXY(position,0,currentval,1);
							_delay_ms(50);
							break;
					   }
					   if(position == 0)
						   multi = 10;
					   else
						   multi = 1;
					   userid += multi * currentval;
                       LCDWriteIntXY(position,0,GetKeyPressed(),1);
                       position++;
               }
				else if(GetKeyPressed()==10){
                       goto start;
               }
			   _delay_ms(50);
       }
	   volatile unsigned int rem = userid%2;
	   if(((userid > 18) || (rem == 1)) || (userid >= EEPROM_read(20))){
			goto start;
	   }
       return userid;
}
 


void openDoor(){   //initially door closed.
       PORTC=1<<PC5; // open the door
       LCDWriteStringXY(4,0,"welcome");
       _delay_ms(60000); // open for 1 minute
      
		PORTC=0;
       
    }
	

void closeDoor(){
        PORTC=1<<PC4;
        LCDClear();
        LCDWriteStringXY(0,0,"Door closed");
        _delay_ms(200);
       
        PORTC=0;
       
   }


int main(void){

DDRC=255;

if(EEPROM_read(21) != 5){//runs only once
	EEPROM_write(20, 2);
	writeEEPROM(0x00,1234);//tempporery user
	EEPROM_write(21, 5);
}


LCDInit(0);//Initialize LCD module ,no curser blinking

LCDClear();//Clear the screen

while(GetKeyPressed()==255){

        LCDWriteStringXY(0,0,"Please enter");
        LCDWriteStringXY(4,1,"the Password");
    }
	

while(1){

	unsigned int password = Getpassword();

	if(validate_password(password)==1){
	
		LCDClear();
		
		openDoor();
		failedAttempts = 0; // number of attempts
		unsigned int m = 600; // wait for 1 miniuts to add new user
		for(unsigned int i = 0;i < m; i++){ 
		
			if(GetKeyPressed() == 12){  // to add new user press # key
				
				
				if(EEPROM_read(20) < 20){
					LCDWriteStringXY(2,0,"add a new user");
					_delay_ms(100);
					unsigned int newpassword = Getpassword();
					// save new user in EEPROM
					writeEEPROM(EEPROM_read(20), newpassword);
					LCDClear();
					LCDWriteStringXY(2,0,"User ID:");
					LCDWriteIntXY(2,1,EEPROM_read(20),2);
					EEPROM_write(20,EEPROM_read(20)+2);
					i = 0;
					_delay_ms(100);
				}
				else{
					LCDWriteStringXY(2,0,"Max no of");
					LCDWriteStringXY(6,1,"users entered.");
					
					_delay_ms(100);
				}
			}
			else if(GetKeyPressed() == 11){ // reset the passwords press 0 key
				LCDWriteStringXY(2,0,"add user id");
				_delay_ms(100);
				unsigned int newuser = Getuserid();
				_delay_ms(100);
				LCDWriteStringXY(0,0,"add new password");
				_delay_ms(100);
				unsigned int newpassword = Getpassword();
				_delay_ms(100);
				writeEEPROM(newuser, newpassword);
				LCDClear();
				LCDWriteStringXY(0,0,"Password Changed!");
				_delay_ms(100);
				i = 0;				
			}
			LCDClear();
			
		_delay_ms(1);

		}

		closeDoor();

	}
	

	else{
	
		LCDClear();
		LCDWriteStringXY(1,0,"Password Error!");
		failedAttempts++;

			if(failedAttempts > 3){
			
				LCDClear();
				LCDWriteStringXY(0,0,"Try Again Later!");
				_delay_ms(180000);
			}
			
		_delay_ms(200);


		}
	}
}     
