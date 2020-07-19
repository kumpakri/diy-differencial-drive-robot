# DIY Differential Drive Robot

Inspired by a free coursera course on mobile robotics (https://www.coursera.org/learn/mobile-robot/), I'm building a differential drive robot from scratch. My goal is to test different control strategies on this robot.

## Building the Robot

### Robot parts
![robot parts](img/all_parts_tiny.jpg)
- chassis
- 2 rubber wheels
- 2 encoder discs with holes
- 2 1:60 motor 3-6 V 120 mA
- caster wheel
- H-bridge L-293
- 2 photoelectric sensors
- 5 ultrasonic distance sensors SR04
- Arduino UNO

> It's advised to pay attantion to the motor placements and cable orientation. I soldered the wires on the motor pins in such a way, that the yellow wires on both motors correspond to the positive polarity when robot moves forwards.

## Motor Control
The kit consists of 2 DC motors and 2 encoder disks. We will use the L293D H-bridge to drive the two motors with varying speed and the photoelectric sensors to count the rotations of the wheels.

The [L293's datasheet](datasheets/L293_H-Bridge.pdf) helps us understand how to use the H-Bridge. For the connection of the H-Bridge with Arduino UNO, I used the scheme shown below. The corresponding driver for the motors is located at [src/main/drive_motors.h](src/main/drive_motors.h).


![stage1 scheme](img/H-bridge+arduino.png)

## Motor Speed Sensor
For the rotary encoders the Infrared slotted optical sensors are used. Those sensors contain the Schmitt-Trigger Invertor in their circuit and work very well for our usecase.

Schematic of the module:
![optical encoder schematic](img/H206_module_schematic.png)
![optical encoder](img/H206_module.jpg)

Schematic connected to Arduino
![optical connected to Arduino](img/H206_module+arduino.png)


## Resources

[1] [Electronics Cookbook: Practical Electronic Recipes with Arduino and Raspberry Pi](https://books.google.cz/books?id=WqmSDgAAQBAJ&)

[2] [Electronics Cookbook's GitHub](https://github.com/simonmonk/electronics_cookbook)