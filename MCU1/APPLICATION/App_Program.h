/*
 * App_Program.h
 *
 *  Created on: Sep 25, 2023
 *      Author: salma
 */

#ifndef APPLICATION_APP_PROGRAM_H_
#define APPLICATION_APP_PROGRAM_H_
#include "../Common/STD_Types.h"

#define DoorOpen 0
#define DoorClosed 1
/*does all the necessary initializations */
void init ();
/*to read the password from the user*/
void read_password ();
/*the interface when the user tries to enter the password*/
void user_interface();
/*check if the password is correct or not*/
u8 check_password ();
/*to put the password configured in the  file into an array */
void pass_arr();
/*in case of entering a correct password*/
void CorrectPassword();
/*in case of entering an incorrect password*/
void WrongPassword();
/*functions to control the door in different cases*/
void CloseDoor();
void OpenDoorFromOutside();
void OpenDoorFromInSide();
/*timer call back function to close the buzzer after about 3 seconds*/
void BuzzerOnTime();
/*timer call back function to close the door after about 5 seconds*/
void DoorOpenTime();
/*external interrupt call back function to control
 *  the door from inside the house */
void DoorControlFromInside();
/*sending the number of  to MCU2 when a change happens */
void SendNoPeople();

#endif /* APPLICATION_APP_PROGRAM_H_ */
