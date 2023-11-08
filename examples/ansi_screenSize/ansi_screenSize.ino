//
//    FILE: ansi_screenSize.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: demo 
//     URL: https://github.com/RobTillaart/ANSI
//
//  use Tera Term or Putty to view.

#include "ansi.h"

/*
 * Example output:
 * +---------------------
 * |
 * |  Screen size: 80x24
 * |
 */

ANSI ansi(&Serial);

void setup() {
  Serial.begin(115200);

  ansi.print(" ");  // some bug, first character written is missing

  if (!ansi.getScreensize(100)) {
    ansi.println(F("\n\n### ANSI escape codes not detected ###\n"
                   "\nThis demo requires a terminal (emulator) with ANSI escape code capabilities."
                   "\nThe terminal you are using can only do TTY."
                   "\nOn Linux 'minicom' can be used. On Windows try Putty or MobaXterm."
                   "\nExample:"
                   "\n   minicom --color=on --baudrate=115200 -D /dev/ttyACM0"
                   "\n\nUTF-8 is also required. Your should see at least one emoji here?: 🐛 🖥 ☎ ❤ ❣ ✂ ✈"
                   "\n"
                   "\nSystem halted."));
    while (1) {}
  }
  ansi.clearScreen();
  ansi.gotoXY(6, 3);
  ansi.print("Screen size: ");
  ansi.print(ansi.screen.x);
  ansi.print("x");
  ansi.println(ansi.screen.y);
  ansi.gotoXY(6, 4);
  ansi.print("\nUTF-8 test. Your should see at least one emoji here?: 🐛 🖥 ☎ ❤ ❣ ✂ ✈");
  delay(1000);

  // Draw border
  ansi.color(ansi.yellow, ansi.blue);
  for (uint16_t y = 1; y <= ansi.screen.y; y++) {
    ansi.gotoXY(1, y);
    if (1 == y || ansi.screen.y == y) {
      ansi.print("+");
      for (uint16_t x = 1; x < ansi.screen.x - 1; x++)
        ansi.print("-");
      ansi.print("+");
    } else {
      ansi.print("|");
      ansi.cursorForward(ansi.screen.x - 2);
      ansi.print("|");
    }
  }
  delay(3000);
}

void loop() {
}


//  -- END OF FILE --
