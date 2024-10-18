# Car Parking Sensor Using ATmega32

This project is a **Car Parking Sensor** system designed to help drivers avoid obstacles while parking. It uses an ultrasonic sensor to measure the distance between the car and nearby objects, displaying the result on an LCD screen and providing LED and buzzer-based warnings.

## Features:
- **Ultrasonic Distance Measurement**: Uses an ultrasonic sensor to measure the distance between the car and an obstacle.
- **LCD Display**: Shows the distance in centimeters and warns the driver when objects are too close ("Stop" warning when <= 5 cm).
- **LED Indicators**: Red, green, and blue LEDs progressively light up as the object gets closer.
- **Buzzer**: Sounds when the distance to the object is less than or equal to 5 cm.

## Hardware Components:
- **ATmega32 Microcontroller**
- **HC-SR04 Ultrasonic Sensor**: Measures distance using ultrasonic waves.
- **16x2 LCD Display**: Displays the distance in real-time.
- **LEDs**: Indicate proximity (Red, Green, Blue).
- **Buzzer**: Alerts when the object is too close.

## How It Works:
1. The ultrasonic sensor continuously measures the distance to an obstacle.
2. The measured distance is shown on the LCD, and the LEDs light up as the distance decreases.
3. A buzzer sounds when the obstacle is too close, ensuring safe parking.

Explore the full code and circuit design [here](Link).

## Acknowledgments:
Special thanks to **Eng. Mohamed Tarek** for guidance during the project.
