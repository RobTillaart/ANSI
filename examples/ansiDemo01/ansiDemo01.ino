//
//    FILE: ansiDemo01.ino
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.0
// PURPOSE: demo
//    DATE: 2020-04-28
//    (c) : MIT
//

#include "ansi.h"

ANSI ansi(&Serial);


void setup()
{
  Serial.begin(115200);

  ansi.clearScreen();
  ansi.bold();
  ansi.println("Hello world");
  ansi.blink();
  ansi.println("Hello world");
  ansi.underline();
  ansi.println("Hello world");
  ansi.low();
  ansi.println("Hello world");
  ansi.reverse();
  ansi.println("Hello world");
  ansi.normal();
  ansi.println("Hello world");
  delay(1000);

  ansi.clearScreen();
  ansi.println("Hello world");
  ansi.println("Hello world");
  ansi.println("Hello world");
  delay(1000);

  ansi.clearScreen();
  for (int i = 1; i < 25; i++)
  {
    ansi.gotoXY(i, 2 * i);
    ansi.println("Hello world");
    delay(100);
  }
  delay(1000);
}

void loop()
{
}

// -- END OF FILE --
