//
//    FILE: ansiDemo02.ino
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.0
// PURPOSE: demo
//    DATE: 2020-04-29
//     URL: https://github.com/RobTillaart/ANSI
//    (c) : MIT
//

#include "ansi.h"

ANSI terminal(&Serial);

int t;
double d;

void setup()
{
  Serial.begin(115200);

  // SPLASH SCREEN
  terminal.clearScreen();
  terminal.gotoXY(8, 10);
  terminal.bold();
  terminal.print("DEMO ANSI TERMINAL");
  terminal.normal();
  delay(5000);
  terminal.clearScreen();
}

void loop()
{
  // DISPLAY TEMPERATURE (dummy)
  terminal.gotoXY(6, 10);
  terminal.print("TEMP:       ");
  terminal.gotoXY(6, 16);
  t = random(100);
  if (t > 70) terminal.foreground(terminal.red);
  terminal.print(t);
  terminal.foreground(terminal.white);

  // DISPLAY HUMIDITY (dummy)
  terminal.gotoXY(7, 10);
  terminal.print(" HUM:       ");
  terminal.gotoXY(7, 16);
  t = random(100);
  if (t > 50) terminal.foreground(terminal.yellow);
  terminal.print(t);
  terminal.foreground(terminal.white);

  // DISPLAY UV (dummy)
  terminal.gotoXY(8, 10);
  terminal.print("  UV:       ");
  terminal.gotoXY(8, 16);
  d = random(10000) * 0.01;
  if (d > 30) terminal.foreground(terminal.green);
  if (d > 50) terminal.foreground(terminal.yellow);
  if (d > 70) terminal.foreground(terminal.red);
  terminal.print(d, 2);
  terminal.foreground(terminal.white);

  // DISPLAY bargraph (dummy)
  terminal.gotoXY(10, 10);
  terminal.print(" BAR:");
  terminal.gotoXY(10, 16);
  int x = random(10);
  for (int i = 0; i < 10; i++) terminal.print(i <= x ? ">" : " ");

  // DISPLAY password (dummy)
  terminal.gotoXY(12, 10);
  terminal.print("PASS:");
  char buffer[20];
  for (int i = 0; i < 16; i++) 
  {
    int x = random(62);
    if (x < 26) buffer[i] = 'A' + random(26);
    if (26 <= x && x < 52) buffer[i] = 'a' + random(26);
    if (52 <= x) buffer[i] = '0' + random(10);
  }
  buffer[16] = 0;
  terminal.gotoXY(12, 16);
  terminal.print(buffer);

  // DISPLAY TIME (dummy)
  terminal.gotoXY(2, 10);
  terminal.print("TIME:         ");
  terminal.gotoXY(2, 16);
  terminal.print(millis()/1000);

  delay(1000);
}

// -- END OF FILE --
