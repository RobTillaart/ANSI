//    FILE: ansi_deviceType.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: demo
//     URL: https://github.com/RobTillaart/ANSI/issues/9

//  NOT TESTED
//  - WITH REAL TERMINAL
//  - with dummies

#include "ansi.h"


ANSI ansi(&Serial);
enum deviceTypes deviceType = UNKNOWN;

void setup() {
  Serial.begin(115200);
  while (!Serial)
    ;
  Serial.println(__FILE__);
}


void loop() {
  if (deviceType == UNKNOWN) {
    deviceType = ansi.deviceType(100);
    Serial.print("DEV_TYPE: ");
    switch (deviceType) {
      case VT52:
        Serial.println("VT52");
        break;
      case VT100:
        Serial.println("VT100");
        break;
      case VT220:
        Serial.println("VT100");
        break;
      default:
        Serial.println("UNKNOWN");
    }
  }
  delay(1000);
}


//  -- END OF FILE --
