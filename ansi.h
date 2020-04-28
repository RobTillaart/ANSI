#pragma once
//
//    FILE: ansi.h
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.0
// PURPOSE: Arduino library to send ANSI escape sequences
//    DATE: 2020-04-28
//     URL: https://github.com/RobTillaart/ANSI
//
// 0.1.0    2020-04-28 initial version
//

#include "Arduino.h"

class ANSI : public Stream
{
public:
  ANSI(Stream * stream = &Serial);

  // Stream interface
  int available();
  int read();
  int peek();

  // CHAR MODES
  void normal()    { print("\033[0m"); };
  void bold()      { print("\033[1m"); };
  void low()       { print("\033[2m"); };
  void underline() { print("\033[4m"); };
  void blink()     { print("\033[5m"); };
  void reverse()   { print("\033[7m"); };
  
  
  // POSITIONING
  void clearScreen();
  void home()      { print("\033[H");  };
  
  void gotoXY(uint8_t x, uint8_t y);
  void cursorUp(uint8_t x);
  void cursorDown(uint8_t x);
  void cursorForward(uint8_t x);
  void cursorBack(uint8_t x);

private:
  size_t write(uint8_t c);

  Stream * 	_stream;
  
};

// -- END OF FILE --
