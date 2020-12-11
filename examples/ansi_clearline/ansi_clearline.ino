//
//    FILE: ansi_clearline.ino
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.0
// PURPOSE: demo
//    DATE: 2020-07-08
//     URL: https://github.com/RobTillaart/ANSI
//    (c) : MIT
//

#include "ansi.h"

ANSI terminal(&Serial);


void setup()
{
  Serial.begin(115200);

  terminal.clearScreen();
  for (int i = 0; i < 20; i++)
  {
    terminal.println("1234567890123456789012345678901234567890");
    delay(100);
  }
  delay(1000);

  for (int i = 0; i < 8; i++)
  {
    terminal.gotoXY(i, 4 + 2 * i);
    terminal.clearLine(terminal.toEnd);
    delay(100);
  }
  delay(1000);
  
  for (int i = 12; i < 20; i++)
  {
    terminal.gotoXY(i, 4 + 2 * i);
    terminal.clearLine(terminal.toStart);
    delay(100);
  }
  delay(1000);

  for (int i = 9; i < 11; i++)
  {
    terminal.gotoXY(i, 4 + 2 * i);
    terminal.clearLine(terminal.entireLine);
    delay(100);
  }
  delay(1000);

  
}

void loop()
{
}

// -- END OF FILE --
