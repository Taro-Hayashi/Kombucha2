# Kombucha スティック
- [キット内容](#キット内容)
- [はんだ付け](#はんだ付け画像を反転する)
- [組み立て](#組み立て)
- [カスタマイズ](#カスタマイズ)
- [おまけ](#おまけ)

## キット内容
![パーツ一覧](img/IMG_4844.jpg)  
||部品名|数| |
|-|-|-|-|
|1|メインボード|1||
|2|ボトムプレート|1||
|3|ミドルプレート1|1||
|4|ミドルプレート2|1||
|5|保護プレート|1||
|6|ネジ（短）|2|3mm|
|7|ネジ（中）|7|4mm|
|8|ネジ（長）|9|6mm|
|9|スペーサー（短）|9|3mm|
|10|スペーサー（長）|7|6mm|
|11|ダイオード|12|1N4148|
|12|リセットスイッチ|1||
|13|ロータリーエンコーダ|1|EVQWGD001|
|14|ゴム足|4||

### キット以外に必要なもの
|部品名|数||
|-|-|-|
|Pro Micro|1|[遊舎工房](https://shop.yushakobo.jp/products/pro-micro) / [TALPKEYBOARD](https://talpkeyboard.net/items/5b24504ba6e6ee7ec60063e3) / [DailyCraftKeyboardコンスルー付き](https://shop.dailycraft.jp/products/promicro_with_conthrou)|
|キースイッチ|11|[Kailh choc V1](https://shop.yushakobo.jp/collections/all-switches/products/pg1350)、もしくは[Kailh Choc V2](https://shop.yushakobo.jp/collections/all-switches/products/kailh-choc-v2)|
|キーキャップ|11|V1は[専用キーキャップ](https://shop.yushakobo.jp/collections/keycaps/For-Choc-v1)、V2は[CherryMX互換](https://shop.yushakobo.jp/collections/keycaps/cherry-mx-%E4%BA%92%E6%8F%9B-%E3%82%AD%E3%83%BC%E3%82%AD%E3%83%A3%E3%83%83%E3%83%97)です。|
|１uトラックボール|1|[遊舎工房](https://shop.yushakobo.jp/products/adtb7m) / [ビットトレードワン](https://btoshop.jp/products/adtb7m) / [Amazon](https://www.amazon.co.jp/dp/B087BVNWYS)|
|レベル変換基板|1|[遊舎工房](https://shop.yushakobo.jp/products/a0800tl-01-1) / [のぎけす屋](https://booth.pm/ja/items/2008258)|
|OLED用ピンヘッダ|1|[遊舎工房](https://shop.yushakobo.jp/products/a1600ph-01-1)|
|OLED用ピンソケット|1|[遊舎工房](https://shop.yushakobo.jp/products/a1600ps-01-1)|
|Micro USB ケーブル|1||
  
### オプション
|部品名|数|||
|-|-|-|-|
|コンスルー 12ピン|2|高さ2.5mm, [使い方](conthrough.md)|[遊舎工房](https://shop.yushakobo.jp/products/31?_pos=1&_sid=ca92edae3&_ss=r&variant=37665714405537) / [TALPKEYBOARD](https://talpkeyboard.net/items/5e056626d790db16e2889233) / [Daily Craft Keyboard](https://shop.dailycraft.jp/products/conthrough)|
|SK6812MINI-E|11|バックライト|[遊舎工房](https://shop.yushakobo.jp/products/sk6812mini-e-10) / [秋月電子通商](https://akizukidenshi.com/catalog/g/gI-15478/)|
|WS2812B|6|アンダーグロー|[遊舎工房](https://shop.yushakobo.jp/products/a0800ws-01-10) / [秋月電子通商](https://akizukidenshi.com/catalog/g/gI-07915/)|
 
### 必要な工具
|工具名|
|-|
|はんだごて|
|こて先クリーナー（こて台）|
|鉛入りはんだ|
|精密ドライバー|
|ニッパー等ダイオードの足を切れるもの|
|エポシキ接着剤|
|Microsoft Edge、もしくはGoogle Chrome|

## はんだ付け
はんだ付けのやり方は動画で見るとわかりやすいです。  
パーツは思ったより壊れないので落ち着いて作業すると失敗しにくいです。  
 - ホームセンターのDCMさんの解説動画(58秒～)  [YouTube](https://www.youtube.com/watch?v=JFQg_ObITYE&t=58s)

### LEDのはんだ付け
LEDを取り付ける場合はメインボードに最初にはんだ付けします。  
 - [LEDの取り付け方](led.md)  

### ダイオード、ピンソケット、リセットスイッチのはんだ付け
ダイオードをD1からD12まで取り付けます。  
足を曲げて裏から差し込みます。  
ダイオードには向きがあります。三角形の先の棒と黒線を合わせましょう。  
![](img/diode1.jpg)  
  
表で更に足を曲げて抜けないようにします。  
ダイオードと並行に曲げるとあとでキースイッチに干渉しにくいです。
![](img/diode2.jpg)  
  
はんだ付けをして足を切ります。  
![](img/diode3.jpg)  

裏からTB1にOLED用ピンソケットを差し込み、表ではんだ付けします。  
![](img/socket1.jpg)  

リセットスイッチを表から差し込み裏ではんだ付けします。  
![](img/reset.jpg)   
フラックスクリーナーを使う場合はここで表面を綺麗にしてください。  
 
### キースイッチのはんだ付け
キースイッチを表から差し込みはんだ付けします。  
![](img/keyswitch1.jpg)  
ここの二つのスイッチはPro Microと接触する可能性があるので、足を切ってからはんだ付けします。
![](img/keyswitch2.jpg)  
  
### Pro Microのはんだ付け
Pro Microを取り付ける場所は二か所あります。使い方に合わせて好きな方を使ってください。  

Pro Microに付属しているピンヘッダの、短い側を基板に差し込みます。  
![](img/IMG_5768.jpg)  

Pro Microを乗せます。TX0, RAW, USBの位置をシルク印刷と合わせましょう。  
![](img/IMG_5769.jpg)  
足をニッパーで切ったらはんだ付けします。  
![](img/IMG_5770.jpg)  
基板側もはんだ付けします。  
![](img/IMG_5771.jpg)  

### 動作テスト
ロータリーエンコーダーとトラックボールを取り付ける前にPro Microに動作ソフト（ファームウェア）を書き込んで動作確認をしましょう。  
キットとPCをUSBケーブルでつないでください。   

下のwebサイトにアクセスしてください。
- https://remap-keys.app/catalog/08BHJ3OcLCe716TwOdDz/firmware

テストファームウェアを選んでFLASHします。
![](img/remap02.jpg)  
![](img/remap03.jpg)  

キットのリセットスイッチを押すとArduino Microが現れるので、クリックして接続します。
![](img/remap04.jpg) 

書き込みが完了したらウィンドウを閉じて大丈夫です。
![](img/remap05.jpg) 

アドレスバーやテキストエディタを使ってすべてのスイッチが反応することを確かめてください。  


### ロータリーエンコーダーのはんだ付け
SW6に表からホイール型のロータリーエンコーダーを取り付けます。  
ピンの位置を確認してツメを穴に差し込みます。  
![](img/wheel1.jpg)  
  
ツメを穴に引っかけてからピンを穴に差し込みます。  
ピンを曲げてしまわないように注意してください。  
![](img/wheel2.jpg)  
  
差し込めたらはんだ付けします。  
![](img/wheel3.jpg)  
 
### トラックボールのはんだ付け
トラックボール、レベル変換基板、OLED用ピンヘッダを画像のようにはんだ付けしましょう。  
![](img/track1.jpg)  

表からレベル変換基板を通します。  
![](img/track2.jpg)  

裏面のピンソケットにピンヘッダを差し込みます。  
![](img/track3.jpg)  
 
お疲れ様でした。再び動作を確認して問題がなければはんだ付けは終了です。

## 組み立て
USBケーブルを抜いてプレートを組付けます。  
アクリルからは保護フィルムを剥がしてください。割れやすいので気をつけましょう。  

メインボードの青丸のネジ穴にスペーサー（長）とスペーサー（短）を止めます。 
![](img/IMG_5774.jpg)   
画像のようにスイッチがついてる側にスペーサー（短）があるようにしてください。  
![](img/IMG_5776.jpg)  

トラックボールが円形の穴に綺麗に収まるように保護プレートをネジ（中）で止めます。
![](img/bottom3.jpg)  
  
メインボードの残りのネジ穴にスペーサー（短）をネジ（短）で取り付けてミドルプレート1（透明）を嵌めます。
![](img/bottom4.jpg)  
トラックボールのケーブルを間に挟んでしまわないように気を付けてください。

ミドルプレート2とバックプレートをネジ（長）で止めます。
![](img/bottom5.jpg)  

![](img/bottom6.jpg)  

キーキャップを取り付けたら先ほどと同様の手順で本番用のファームウェアに更新しましょう。
- https://remap-keys.app/catalog/08BHJ3OcLCe716TwOdDz/firmware
![](img/remap06.jpg)  

裏面4隅にゴム足を貼ったら完成です。  
![](img/full.jpg)  

## カスタマイズ
![](img/keymap.jpg)  
[Keyboard Layout Editor で見る](http://www.keyboard-layout-editor.com/#/gists/8a9cd944cc1cf5abed875719608a3e3a)  

使わないキーを削除したり使用頻度の高いキーを押しやすい位置に変更してみましょう。  
  
ChromeかEdgeでRemapにアクセスしてください。  
- Remap https://remap-keys.app/
  
![](img/remap1.png)  
左を選ぶとキーボードを選択できます。  
  
ドラッグアンドドロップで変更が終わったら右上のflashボタンを押すと反映されます。  
![](img/remap3.png)  
  
## その他

レベル変換基板はソケットを使わずに基板にはんだ付けしてしまっても構いません。  
コンスルーから4ピンを切り出して使うとOLED用ピンヘッダ、OLED用ピンソケットは使わずに作ることもできます。  
![](img/IMG_5760.jpg)  

ファームウェアのフォルダ  
https://github.com/Taro-Hayashi/qmk_firmware/tree/tarohayashi/keyboards/tarohayashi/kombucha
  
VIA用JSONファイル [kombucha.json](https://github.com/Taro-Hayashi/Kombucha/releases/download/14.15/kombucha.json)  
  
プレートのデザインデータ  
[kombucha_plates.zip](https://github.com/Taro-Hayashi/Kombucha/releases/download/14.31/kombucha_plates.zip)  
発注先のルールに沿ってデータを修正してください。  
  
ご不明な点があればBOOTHのメッセージかtwitterでいつでも聞いてください。  
  
foostan様のフットプリントを流用、改変して使わせていただきました。  
https://github.com/foostan/kbd/  
https://github.com/foostan/kbd/blob/master/LICENSE  
  
plut0nium様のフットプリントを流用、改変して使わせていただきました。  
https://github.com/plut0nium/0xLib  
https://github.com/plut0nium/0xLib/blob/master/LICENSE.txt  
  
<a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/"><img alt="クリエイティブ・コモンズ・ライセンス" style="border-width:0" src="https://i.creativecommons.org/l/by-sa/4.0/88x31.png" /></a><br />この キット は <a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/">クリエイティブ・コモンズ 表示 - 継承 4.0 国際 ライセンス</a>の下に提供されています。

- BOOTH: https://tarohayashi.booth.pm/items/3252673  
