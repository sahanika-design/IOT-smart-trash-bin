# IOT-smart-trash-bin
Smart trash bin that automatically opens using an ultrasonic sensor and Arduino for touchless waste disposal. 

# Project Overview
The Smart Trash Bin is an automatic waste management system that opens and closes its lid without human touch. It uses an ultrasonic sensor to detect the presence of a person and a servo motor to control the lid. This project helps maintain hygiene and promotes a smart, contactless environment.

# Objectives
To design a touchless dustbin system
To improve hygiene and reduce germ spread
To demonstrate IoT/embedded system concepts
To build a low-cost smart solution

# Components
Arduino Uno-1
Ultrasonic Sensor (HC-SR04)-1
Servo Motor (SG90)-1
Jumper Wires-As required
Breadboard-1
Dustbin with lid-1
Power Supply-1

# Working Principle
The ultrasonic sensor continuously measures the distance in front of the bin.
When a person’s hand comes within the threshold distance (e.g., 20 cm), the sensor detects it.
Arduino processes the signal.
Arduino sends a command to the servo motor.
The servo motor rotates and opens the lid.
After a few seconds, the lid automatically closes.

# Circuit Connections
Ultrasonic Sensor → Arduino
VCC → 5V
GND → GND
TRIG → Digital Pin 9
ECHO → Digital Pin 10

Servo Motor → Arduino
Red → 5V
Brown → GND
Orange → Digital Pin 6

# How to Run the Project
Assemble the circuit as shown above
Upload the Arduino code
Power the Arduino
Bring your hand near the sensor
The lid will open automatically

# Future Enhancements
->Add IoT monitoring
->Add garbage level detection
->Add mobile app control
->Solar power support
->Voice assistant integration
