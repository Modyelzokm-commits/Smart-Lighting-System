# Smart Lighting System 💡

## Overview
This project is an automated smart lighting system built with Arduino as part of my engineering coursework at Horus University. It is designed to conserve energy by turning on lights only when it is dark AND motion is detected. I independently designed the hardware wiring, wrote the embedded C code, and successfully built and tested the physical prototype.

## Features
- **Ambient Light Detection:** Uses an LDR sensor to detect whether it is day or night.
- **Motion Sensing:** Uses 3 Infrared (IR) sensors to detect movement in specific zones.
- **Real-time Monitoring:** Displays the current status of the LEDs on a 16x2 LCD using I2C.
- **Energy Efficient:** Lights remain completely off during the day or when no motion is present.

## Hardware Components
- Arduino (Uno/Nano/Mega)
- 1x LDR (Light Dependent Resistor) Sensor Module
- 3x IR (Infrared) Obstacle Avoidance Sensors
- 3x LEDs
- 1x 16x2 LCD Display with I2C module
- Jumper wires & Breadboard

## How It Works
1. The **LDR sensor** continuously reads the ambient light level.
2. If light is present -> All LEDs stay OFF, and the LCD displays that light is present.
3. If it is dark -> The system activates the **IR sensors**.
4. If an IR sensor detects motion -> The corresponding LED turns ON, and the LCD updates to show which LED is active (e.g., "led1:on").
5. When motion ends, the LED turns off automatically.
