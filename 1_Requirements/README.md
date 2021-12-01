# Requirements
## Introduction:
This project is digital password based Door Lock in which microcontroller is the heart of the system, the user put their password, if the password is correct the door is unlock , it is used in more secured areas and also in lockers.

## Objective:

In day to day life security of any object or place is plays a major role. This project has considered about that and created a secure access for a door which needs a password to open the door.  Using keypad it enters a password to the system and if it is entered correctly door is open by motor which is used to rotate the handle of the door lock. It will give three attempts to enter the password when it is entered incorrectly at the first time. Some features like adding new users and changing old password are configure by the keypad.LCD module is used to display messages to the user
## Features:
Easy to use the lock.

quick response when is entered.

user also change their password.

user can entered their password through keypad .

new user is also add in the system.

# SWOT Analysis
## Strengths
System does not require internet.

New user can be added.


user can also change their password in the lock using keypad and LCD.

## Weakness
If anyone knows your password then he/she can change it if wants.

IF system is failed due to disturbance in their ciruit(circuit failure), then the door is continously opens or continously closed.

Maximum 10 user can be added.
## Oppotunities
Expand capabilities to extend further users (upto 10) in the system.

users can their password.

## Threats
since this device is working with external power source if there is a power cut system will be down.for that it is better if it include internal power source for the device to work when it is no external power..



## 4W's and 1H

WHEN

once the system is fixed in the door, it can continously work 24*7. 

WHAT

It is a password protected lock so no one can opened the door without password.

WHERE

 

WHOM

Only you can open this lock, because when the password is setting , you entered your own password, no one knows it.
 
HOW

The Door is Only opened when you entered your correct password.

## DETAILS REQUIREMENTS
## High Level Requirements 
| ID | Description | Category | Status | 
| ----- | ----- | ------- | ---------|
| HR01 | 1-9 keys can be used to set passwords | Techincal | IMPLEMENTED | 
| HR02 | When it is entered a 4 digit password by the user it will display on LCD as “****”. Therefore anyone else can’t see what the user enters | Techincal | IMPLEMENTED |
| HR03 | After 1minuts time door is locked automatically. | Techincal | IMPLEMENTED |
| HR04 | If it is a wrong password user received another 3attempts to enter the correct one.then wait for 3 min to log in again. | Techincal | IMPLEMENTED |

### Low level Requirements
 
| ID | Description | HLR ID | Status (Implemented/Future) |
| ------ | --------- | ------ | ----- |
|LR01| After opening the door if user wants to change his password, after pressing “0” key and giving user id user can change his password.|HR01|IMPLEMENTED|
|LR02| If user wants to add more people to the system after opening the door pressing “#” key, user can add more users. System will give user id to each password. |HR01|IMPLEMENTED|
|LR03| 10 users can be added to this system  | HR03 |IMPLEMENTED|
|LR04| When it make any mistake while entering the password user can delete it by using “*” key. |HR04| IMPLEMENTED |
