# Arduino Distance Tracker 

The goal of this project is to create a distance tracker that displays how far away an object is from the sensor using 2 RGB LEDs. Based on the code in the **main.cpp** file the lights will turn the following colors:

|Distance (x)|RGB LED #1|RGB LED #2|
|:------------:|:------------:|:------------:|
|2cm < x <= 52cm|red|red|
|52cm < x <= 102cm|red|off|
|102cm < x <= 152cm|blue|off|
|152cm < x <= 202cm|blue|blue|
|202cm < x <= 252cm|green|off|
|252cm < x <= 302cm|green|green|
|302cm < x <= 352cm|white|off|
|352cm < x <= 400cm|white|white|
|400cm < x|off|off|

## 1.0 THE CIRCUIT
### 1.1 Components
- 4 pin RGB LED (2)
- 220k resistors (6)
- Arduino Leonardo (1)
- [HC-SR04](https://lastminuteengineers.com/arduino-sr04-ultrasonic-sensor-tutorial/) module (1)
- Male to male wires (13)

### 1.2 Connections
#### 1.2.1 HC-SRO4 Module
|HC-SR04 Pin|Arduino Pin|
|:-------------:|:-------------:|
|Vcc|5V|
|Trig|pin 11|
|Echo|pin 13|
|GND|GND|

#### 1.2.2 RGB LED 
|RGB LED|Arduino Pin|LED Number|
|:-----------------:|:-----------------:|:-----------------:|
|red + resistor|pin 7|1|
|red + resistor|pin 4|2|
|green + resistor|pin 6|1|
|green + resistor|pin 3|2|
|blue + resistor|pin 5|1|
|blue + resistor|pin 2|2|

# 1.3 Circuit Diagram
![Circuit Diagram](/photos/DistanceTrackerCircuit.jpg?raw=true "Circuit Diagram")

## 2.0 BUILD INSTRUCTIONS
All the files in this project are in C++. The uploaded build works in VSCode with the [PlatformIO IDE](https://platformio.org/) add in.  To install PlatformIO you will need to install the Arduino IDE and the Visual Studio Code plugin for PlatformIO. Instructions on how to install these programs can be found [here](https://www.youtube.com/watch?v=dany7ae_0ks).