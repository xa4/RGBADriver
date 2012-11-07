#include <Wire.h>
#include <RGBADriver.h>  

RGBADriver driver;

void setup()
{
  driver.init();
}

void loop()
{
  // turn off all 4 channels (r,g,b,a) and wait a second
  driver.update(0,0,0,0);
  delay(1000);
  // turn on all 4 channels (r,g,b,a) and wait a second
  driver.update(4095,40952,4095,4095);
  delay(1000);
  
}