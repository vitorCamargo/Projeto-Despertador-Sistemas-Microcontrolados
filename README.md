# Alarm Clock
👨🏽‍💻⏰ Assignment for 'Microcontrolled Systems' subject about a alarm clock in Arduino.

## Main Idea
The general idea is to develop an alarm clock using an Arduino platform.

![Image of Idea](https://github.com/vitorCamargo/alarm-clock/blob/master/idea.png)

### Materiais e Métodos
Para projetar o circuito serão utilizados os seguintes materiais:
- 1 Arduino Mega 2560
- 1 LCD 16x2
- 1 Buzzer Module
- 1 HC-06 Bluetooth Module
- 1 RTC (Real Time Clock) Modulo
- 1 LED 5mm
- 1 Matrix Keybord
- 3 Resistors
- Some Jumpers

The program code will be made in C ++ using Arduino IDE.

### How it works
At the end of the project, it will be possible to establish a connection via Bluetooth, between the mobile phone and the project, using the developed application. This way, even in the app, it will be possible to choose a time for the alarm clock. In doing so, a signal will be sent to the project's Bluetooth Module indicating the selected time. This time will be saved in Arduino EEPROM, and when the selected time is equal to the current time indicated by the RTC Module, the Buzzer Module and the phone will start to sound alarm sounds.
In addition, a random addition or multiplication operation will be displayed on the 16x2 LCD Display, and alarms will ***only*** stop sounding when the user enters the result on the LCD Display using the Dot Matrix.
