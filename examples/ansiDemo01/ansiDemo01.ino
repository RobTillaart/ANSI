//
//    FILE: ansiDemo01.ino
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.1
// PURPOSE: demo
//    DATE: 2020-04-28
//     URL: https://github.com/RobTillaart/ANSI
//    (c) : MIT
//

#include "ansi.h"

ANSI terminal(&Serial);


void setup()
{
  Serial.begin(115200);

  terminal.clearScreen();
  terminal.bold();
  terminal.println("Hello world");
  terminal.blink();
  terminal.println("Hello world");
  terminal.underline();
  terminal.println("Hello world");
  terminal.low();
  terminal.println("Hello world");
  terminal.reverse();
  terminal.println("Hello world");
  terminal.normal();
  terminal.println("Hello world");
  delay(1000);

  terminal.clearScreen();
  terminal.println("Hello world");
  terminal.println("Hello world");
  terminal.println("Hello world");
  delay(1000);

  terminal.clearScreen();
  for (int i = 1; i < 25; i++)
  {
    terminal.gotoXY(i, 2 * i);
    terminal.println("Hello world");
    delay(100);
  }
  delay(1000);

  terminal.clearScreen();
  // 4 bit color test
  for (int color = 0; color < 16; ++color) {
    terminal.foreground(color);
    terminal.print("foreground");
    terminal.normal();
    terminal.background(color);
    terminal.println("background");
    terminal.normal();
  }

  delay(1000);

  terminal.clearScreen();
  for (int color = 0; color < 16; ++color) {
    terminal.color(color, (color + 1) % 16);
    terminal.println("foreground and background");
    terminal.normal();
  }

  delay(1000);

  terminal.clearScreen();
  // 8 bit color test
  terminal.foreground(terminal.rgb2color(180, 0, 158));
  terminal.print("foreground");
  terminal.normal();
  terminal.background(terminal.rgb2color(180, 0, 158));
  terminal.println("background");
  terminal.normal();

  terminal.foreground(terminal.grey2color(64));
  terminal.print("foreground");
  terminal.normal();
  terminal.background(terminal.grey2color(64));
  terminal.println("background");
  terminal.normal();

  delay(1000);
  terminal.normal();
}

void loop()
{
}

// -- END OF FILE --
