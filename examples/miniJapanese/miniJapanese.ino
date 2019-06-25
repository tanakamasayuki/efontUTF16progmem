#include <M5StickC.h>
#include "efontUTF16progmemOnlyMiniJapanese.h"
#include "efontUTF16progmemM5StickC.h"

void setup() {
  M5.begin();
  M5.Lcd.setRotation(0);
  M5.Lcd.setCursor(0, 0);

  printEfont("Hello", 0, 16*0);
  printEfont("こんにちは", 0, 16*1);
}

void loop() {
}
