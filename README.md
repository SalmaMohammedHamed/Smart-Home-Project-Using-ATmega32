# Smart Home Project Using ATmega32


The Project consists of Two ATmega32 Microcontrollers
MCU1:
-If a user wants to enter the home he/she clicks on a button to see the enterfe screen
-The user has 2 attemps to enter the password correctly
-If the user enters an incorrect password 3 times, the screen prins "Wrong" and an alarm buzzer works for about 3 seconds
-if the user enters a correct password the door "Servo Motor" opens  outomatically
-when someone enters the home MCU1 sends this information for MCU2
-there is a button inside the house to close/open the door from inside the house
-if the door stayed open for about 5 seconds the door closed outomatically
-if someone opens the door from inside and left the house MCU2 sends the number of people inside the house decreased

MCU2:
-MCU2 has 3 systems
-fire fighter system: consists of gas sensor, led(represents fire extinguisher) and a warning buzzer. so when the sensor read =1 the buzzer and the fire extinguisherare on.(this system is working all time).
-lighting system: consists of LDR and led. the led light level is relative to the light level in the room.(this system is only on when there is someone the house).
-Air conditioner System: consists of LM35 and a led (represents the air conditioner).(this system is only on when there is someone the house).

---

## Schematic 
*Full Project Schematic*
-
![fullschem](/fullschem.jpg)
-

---
*MCU 1: Smart Door System*
-
![mcu1](/mcu1.jpg)
-


Layers: 
-     
       App: - smart door Application Driver

       HAL:  - Buzzer Driver
             - KeyPad Driver
             - LCD Driver
             - Led Driver
             - Servo Motor Driver
             - Switch Driver
             
      MCAL:  - DIO Driver
             - EXTI Driver
             - GIE Driver
             - SPI Driver
             - Timers Driver
             - UART Driver             
        

---
*MCU 2: Smart Home System*
-
![mcu2](/mcu2.jpg)
-


Layers: 
-       
       App: - smart Home Application Driver

       HAL:  - Buzzer Driver
             - Gas Sensor Driver
             - LCD Driver
             - LED Driver
             - LDR Driver
             - LM35 Driver
             - Relay Driver
             - Switch Driver
             
      MCAL:  - DIO Driver
             - ADC Driver      
             - EXTI Driver
             - GIE Driver
             - SPI Driver
             - Timers Driver
             - UART Driver
       
        OS:  - Operating System scheduler Driver 
        

---
## Team Members

 [Salma mohammed](https://www.linkedin.com/in/salma-hamed-8b301b24a/)
 -
 [Saad Elsokkary](https://www.linkedin.com/in/your-profile)
 -
 [Mohamed Ahmed Abdalaziem Abdullah](https://www.linkedin.com/in/mohamed-ahmed-33187b293)
 -
---
---
## vedios

 ([](https://drive.google.com/drive/folders/10I-2fsUfwLhYm-Tar9FM51uLZSgS3ID2?usp=sharing)
 
---
