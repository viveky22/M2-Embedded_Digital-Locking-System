# M2-Embedded_Digital-Locking-System

In day to day life security of any object or place is plays a major role. This project has considered about that and created a secure access for a door which needs a password to open the door.  Using keypad it enters a password to the system and if it is entered correctly door is open by motor which is used to rotate the handle of the door lock. It will give three attempts to enter the password when it is entered incorrectly at the first time. Some features like adding new users and changing old password are configure by the keypad.LCD module is used to display messages to the user.

## Software design

The basic concept of software design is it should scan the pressed key values by the microcontroller and according to that signal change of the port D it return which key has pressed and check whether that entered 4 digit password and stored password in the EEPROM are matching. If they will match motor is activated and door is opened.

Results and Analysis

## Badges
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/41b01c1a1fca45058306bbabdf0bf06c)](https://www.codacy.com/gh/viveky22/M2-Embedded_Digital-Locking-System/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=viveky22/M2-Embedded_Digital-Locking-System&amp;utm_campaign=Badge_Grade)

[![CI](https://github.com/viveky22/M2-Embedded_Digital-Locking-System/actions/workflows/main.yml/badge.svg)](https://github.com/viveky22/M2-Embedded_Digital-Locking-System/actions/workflows/main.yml)

[![GitInspector](https://github.com/viveky22/M2-Embedded_Digital-Locking-System/actions/workflows/git%20inspector.yml/badge.svg)](https://github.com/viveky22/M2-Embedded_Digital-Locking-System/actions/workflows/git%20inspector.yml)

[![cppcheck-action-test](https://github.com/viveky22/M2-Embedded_Digital-Locking-System/actions/workflows/cppcheck.yml/badge.svg)](https://github.com/viveky22/M2-Embedded_Digital-Locking-System/actions/workflows/cppcheck.yml)

## Bill.

| S.No. | Component Description | Quantity |
| ------ | --------- | ------ |
|1| ATmega328 Microcontroller.| 1 |
|2| LCD |1|
|3| Motor  | 1 |
|4| Realy for motor | 1 
|5| Resistors | 4 |
|6| 4x3 keypad| 1|
