RGBADriver library
==================

arduino library for controlling the RGBA LED driver available at thefabric.com

usage:
------

Download the library and place it in your "library" folder.
Run Arduino and load an example from the File menu.
Save this example in your sketch folder and start experimenting :)

example code:
-------------
<pre>
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
</pre>