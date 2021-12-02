# Output
When we entre the code through the 4x3 keypad and if your password is correct , the lock ia opens and automatically closed after 1 minutes,but if your password is incoreect, there are three more attempt to entre correct password and open the lock.

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
