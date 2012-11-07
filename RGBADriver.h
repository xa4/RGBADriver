/*
  RGBADriver.h - Library for communicating with
  the RGBADriver board from TheFabric.com
  Created by Xavier Righetti, November 7, 2012.
  Released into the public domain.
*/
#ifndef RGBADriver_h
#define RGBADriver_h

class RGBADriver
{
  public:
    RGBADriver();
    void update(int r, int g, int b, int a);
    void init();
};

#endif