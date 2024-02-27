# Smart Home Project Using ATmega32

## Overview
The Smart Home Project utilizes two ATmega32 microcontrollers (MCU1 and MCU2) to create a comprehensive smart home system. MCU1 manages the smart door system, allowing authorized access to the home, while MCU2 controls various home automation systems such as fire safety, lighting, and climate control.

## MCU1: Smart Door System
MCU1 features a smart door system with the following functionalities:
- User authentication using a password entered via a keypad.
- Automatic door opening using a servo motor upon successful authentication.
- Sending entry notifications to MCU2.
- Interior button for manual door control.
- Automatic door closure after a preset time if left open.
- Communication with MCU2 to update the number of occupants in the house.

## MCU2: Smart Home System
MCU2 incorporates three subsystems for home automation:
1. Fire Fighter System:
   - Utilizes a gas sensor to detect fires.
   - Activates a warning buzzer and LED representing a fire extinguisher in case of fire.
2. Lighting System:
   - Adjusts LED brightness based on ambient light levels using an LDR (Light Dependent Resistor).
3. Air Conditioner System:
   - Regulates room temperature using an LM35 temperature sensor and LED indicator.

## Schematic
### Full Project Schematic
![Full Project Schematic](/fullschem.jpg)
### MCU1: Smart Door System
![MCU1 Schematic](/mcu1.jpg)

## Software Architecture
The project's software architecture is divided into layers:
- *Application (App)*: Implements the smart home and smart door application logic.
- *Hardware Abstraction Layer (HAL)*: Provides drivers for various hardware components such as sensors, actuators, and peripherals.
- *Microcontroller Abstraction Layer (MCAL)*: Offers low-level drivers for MCU peripherals.
- *Operating System (OS)*: Provides a scheduler for task management and multitasking.

## Team Members
- [Salma Mohammed](https://www.linkedin.com/in/salma-hamed-8b301b24a/)
- [Saad Elsokkary](https://www.linkedin.com/in/your-profile)
- [Mohamed Ahmed Abdalaziem Abdullah](https://www.linkedin.com/in/mohamed-ahmed-33187b293)

## Videos
[Watch Project Videos](https://drive.google.com/drive/folders/10I-2fsUfwLhYm-Tar9FM51uLZSgS3ID2?usp=sharing)

---

This Smart Home Project showcases the integration of hardware and software to create a sophisticated home automation system. For further inquiries or collaboration opportunities, please contact the team members.
