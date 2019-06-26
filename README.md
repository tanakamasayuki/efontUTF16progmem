# efont UTF16 Font Data(PROGMEM)

http://openlab.ring.gr.jp/efont/unicode/

/efont/ Unicode Font をArduinoで使えるようにしました。

## 概要

/efont/ Unicode Fontに収録されているf16.bdfとb16.bdfを利用して1文字32バイトの16ピクセルフォントデータです。
全角文字はf16.bdfを利用し、U+00FFまでの文字は半角としb16.bdfを利用しています。

## 使い方

ダウンロードしたフォルダをArduinoのlibrariesフォルダにコピーをするか、必要なファイルだけプロジェクトの中にコピーしてください。

## フォントサイズを減らす方法

フォントは256文字単位で管理されており、256文字単位で読み込まない設定が可能です。
標準だと1.4M程度フォントデータがあり、PROGMEMに転送できない場合があります。
No OTAなどプログラムサイズを増やすか、不要なフォントを減らしてサイズを小さくしてください。

efontUTF16progmem.hより前に、読み込まないフォントを指定することで、読み込み量が小さくなります。


```
#define __EFONT_UTF16_PROGMEM_DISABLE_0XFF__    // Specials
#include "efontUTF16progmem.h"
```

上記のように256字単位で、読み込まないブロックを指定することができます。
複数のブロックをあらかじめ宣言してあるものもあります。

```
#include "efontUTF16progmemOnlyMiniJapanese.h"
#include "efontUTF16progmem.h"
```

efontUTF16progmemOnlyMiniJapanese.hは常用漢字とよく使いそうな記号が使え、旧字や中国語、ハングル文字、諸外国語などは使えないコンパクトなフォントデータです。

## フォントサイズ

| オプション                          | フォント容量 |
|-------------------------------------|--------------|
| Full                                | 1,441,792    |
| efontUTF16progmemDisableAll.h       | 0            |
| efontUTF16progmemDisableCJK.h       | 507,904      |
| efontUTF16progmemDisableHang.h      | 1,081,344    |
| efontUTF16progmemOnlyCJK.h          | 1,007,616    |
| efontUTF16progmemOnlyMiniJapanese.h | 753,664      |

## M5StickC以外での利用方法

描画周りについては機種ごとに違うため、各自機種に合わせて作り直してください。

## サンプルコード
```
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
```
