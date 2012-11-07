/*
  RGBADriver.h - Library for communicating with
  the RGBADriver board from TheFabric.com
  Created by Xavier Righetti, November 7, 2012.
  Released into the public domain.
*/
#include "RGBADriver.h"

#if ARDUINO>=100
  #include <Arduino.h> // Arduino 1.0
#else
  #include <WProgram.h> // Arduino 0022
#endif
#include <Wire.h>

RGBADriver::RGBADriver()
{
  #define PCA9685 0x41// I2C address for PCA9865
  #define MODE1 0 // location for Mode1 register address on the PCA9685
  #define MODE2 0x01 // location for Mode2 register address on the PCA9685

  #define LED_PIN  9   // activity LED

  #define LED_G    0x12  // LED 0
  #define LED_B    0x0A  // LED 1
  #define LED_R    0x0E  // LED 2
  #define LED_A    0x06  // LED 3
}

void RGBADriver::init()
{
  Wire.begin(); // also set this device to address 4, not required
  Wire.beginTransmission(PCA9685);
  Wire.write((byte)MODE1);
  Wire.write(0xa1); // set up for auto increment
  Wire.endTransmission();
  // set up for tristate outputs
  Wire.beginTransmission(PCA9685);
  Wire.write(MODE2);
  Wire.write((byte)0x04); // INVERT->0 (external driver used); OUTDRV->1 (totem pole)
  Wire.endTransmission();
}

void RGBADriver::update(int r, int g, int b, int a)
{
  Wire.beginTransmission(PCA9685);
  Wire.write(LED_R);
  Wire.write((byte)0x00); // set to output start lsb
  Wire.write((byte)0x00); // set to output start msb
  Wire.write((byte)(r)); // set to output end lsb
  Wire.write((byte)(r >> 8)); // set to output end msb
  Wire.endTransmission();
  
  Wire.beginTransmission(PCA9685);
  Wire.write(LED_G);
  Wire.write((byte)0x00); // set to output start lsb
  Wire.write((byte)0x00); // set to output start msb
  Wire.write((byte)(g)); // set to output end lsb 
  Wire.write((byte)(g >> 8)); // set to output end msb
  Wire.endTransmission();
  
  Wire.beginTransmission(PCA9685);
  Wire.write(LED_B);
  Wire.write((byte)0x00); // set to output start lsb
  Wire.write((byte)0x00); // set to output start msb
  Wire.write((byte)(b)); // set to output end lsb
  Wire.write((byte)(b >> 8)); // set to output end msb
  Wire.endTransmission();  
  
  Wire.beginTransmission(PCA9685);
  Wire.write(LED_A);
  Wire.write((byte)0x00); // set to output start lsb
  Wire.write((byte)0x00); // set to output start msb
  Wire.write((byte)(a)); // set to output end lsb
  Wire.write((byte)(a >> 8)); // set to output end msb
  Wire.endTransmission();
}
