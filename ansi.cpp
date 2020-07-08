//
//    FILE: ansi.cpp
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.1
// PURPOSE: Arduino library to send ANSI escape sequences
//    DATE: 2020-04-28
//     URL: https://github.com/RobTillaart/ANSI
//
// 0.1.0    2020-04-28 initial version
// 0.1.1    2020-05-27 update library.json
//

#include "ansi.h"

ANSI::ANSI(Stream * stream)
{
  _stream = stream;
}

int ANSI::available()
{
	return _stream->available();
}

int ANSI::read()
{
	return _stream->read();
}

int ANSI::peek()
{
	return _stream->peek();
}

void ANSI::clearScreen()
{
  print("\033[2J");
  home();
}
	
void ANSI::clearLine(uint8_t clear)
{
  print("\033[");
  print(clear);
  print("K");
}
	
void ANSI::gotoXY(uint8_t x, uint8_t y)
{
  print("\033[");
  print(x);
  print(";");
  print(y);
  print("H");
}

void ANSI::cursorUp(uint8_t x)
{
  print("\033[");
  print(x);
  print("A");
}

void ANSI::cursorDown(uint8_t x)
{
  print("\033[");
  print(x);
  print("B");

}

void ANSI::cursorForward(uint8_t x)
{
  print("\033[");
  print(x);
  print("A");

}

void ANSI::cursorBack(uint8_t x)
{
  print("\033[");
  print(x);
  print("A");

}

size_t ANSI::write(uint8_t c)
{
  // todo add line buffer
  _stream->write(c);
  return 1;
}
  
// -- END OF FILE --
