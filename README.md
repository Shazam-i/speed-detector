# Speed-Detector
Introduction
This project is a real-time Speed Detection System that combines hardware components like IR sensors, an Arduino-compatible microcontroller, and an I2C LCD display with the power of C++ programming. The core logic of the system revolves around calculating the time difference between two sensor triggers and using that to compute the object’s speed. With effective use of functions, real-time control logic, and basic C++ structures, this project demonstrates a smooth integration of software with hardware for an intelligent measurement system.
Problem Statement
In many industries and educational setups, there's a need for accurate speed measurement of moving objects, but without the complexity and cost of industrial speed sensors. This project solves that problem by using two inexpensive IR sensors connected to a microcontroller. With the help of millis(), a standard C++ time function for Arduino, and careful logic control, we compute speed using fundamental physics formulas. The output is displayed in real-time on an LCD, and debugged using Serial communication, showcasing both software logic and sensor-based interaction.
Objectives
●	Use two IR sensors to detect motion triggers
●	Record time using millis() and calculate speed using C++
●	Display speed output using a 16x2 I2C LCD
●	Highlight the use of functions, conditionals, and data types in C++
●	Implement debounce and control logic to prevent false triggering
●	Provide a low-cost, embedded solution for motion-based speed calculation
●	Improve skills in both embedded C++ and sensor integration

Project Working
Basic Working
The speed detection system uses two IR sensors placed 20 cm apart, connected to digital pins 2 and 3 of a microcontroller. When an object passes the first sensor, the system records the time using millis() and sets a flag to begin tracking. Once the second sensor is triggered, it captures the end time and calculates the time difference.
Using the formula speed = distance/time, and converting it to km/h, the speed is calculated in C++ with float precision. The result is shown on a 16x2 I2C LCD using lcd.print() and also sent to the Serial Monitor for verification. Core C++ features like if-else conditions, constants, and built-in functions (millis(), digitalRead(), delay()) handle timing, sensor input, and flow control. This creates a reliable, real-time system with minimal hardware and clean software logic.
Integration of Hardware and Software
The project is built around the idea of capturing the time it takes for an object to move between two IR sensors and using that time to calculate speed. Here's how each component works together in the system:
●	IR Sensors (2x): Detect when an object passes. The sensors are placed 20 cm apart. When the object triggers the first sensor, the timer starts. When it triggers the second sensor, the timer stops.
●	Microcontroller (Arduino/Uno/Nano): Captures time using millis() and performs the speed calculation using the formula:
 Speed (m/s)=Distance / Time       and        Speed (km/h)=Speed (m/s) x 3.6
●	LCD Display (I2C 16x2): Shows the final speed in km/h for the user in a clean, readable format.
