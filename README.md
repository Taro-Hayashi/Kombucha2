# Kombucha ジョイスティック 左手向けビルドガイド（[右手向け](README_R.md)）
- [キット内容](#キット内容)
- [準備](#準備)
- [はんだ付け](#はんだ付け)
- [組み立て](#組み立て)
- [カスタマイズ](#カスタマイズ)
- [meishi Trackball Moduleを使う](#meishi-Trackball-Moduleを使う)
- [その他](#その他)

## キット内容
![](img/IMG_2575.jpg)  
||部品名|数| |
|-|-|-|-|
|1|メインボード|1||
|2|トッププレート|1||
|3|ボトムプレート|1||
|4|ジョイスティック基板|1||
|5|アクリルプレート|4||
|6|スペーサー（細）（短）|4|黄銅・3mm|
|7|スペーサー（細）（長）|4|黄銅・7mm|
|8|スペーサー（太）（短）|9|ステンレス・7mm|
|9|スペーサー（太）（長）|12|ステンレス・16mm|
|10|ねじ（短）|14|黒・4mm|
|11|ねじ（長）|12|銀|
|12|スプリング|2||
|13|5ピンヘッダ|2||
|14|7ピンヘッダ|3||
|15|5ピンソケット|1||
|16|7ピンソケット|1||
|17|スイッチソケット|9||
|18|ホイールエンコーダー|1|11mm|
|19|ホイール|1||
|20|ジョイスティック|1||
|21|キャップ|1||
|22|タクタイルスイッチ|1|7.5mm|
|23|タクタイルスイッチSMD|1|7mm|
|24|ダイオード|11||
|25|LED|9||
|26|ゴム足|4|

### キット以外に必要なもの
|部品名|数||
|-|-|-|
|XIAO RP2040|1|[TALP KEYBOARD](https://talpkeyboard.net/items/63534f58f5197322fceb6487)、[秋月電子通商](https://akizukidenshi.com/catalog/g/gM-17044/)|
|Cherry MX互換キースイッチ|1|[TALP KEYBOARD](https://talpkeyboard.net/?category_id=5f2d0726afaa9d40152b2cec)、[遊舎工房](https://shop.yushakobo.jp/search?sort_by=relevance&q=Cherry+MX&type=product&options%5Bprefix%5D=last&options%5Bunavailable_products%5D=last&filter.v.price.gte=&filter.v.price.lte=&filter.v.m.my_fields.switch_type=Clicky&filter.v.m.my_fields.switch_type=Linear&filter.v.m.my_fields.switch_type=Silent+Linear&filter.v.m.my_fields.switch_type=Silent+Tactile&filter.v.m.my_fields.switch_type=Tactile)|
|Cherry MX互換キーキャップ（1U）|1|[TALP KEYBOARD](https://stores.jp/search?q=チェリーMX&store=talpkeyboard)、[遊舎工房](https://shop.yushakobo.jp/collections/keycaps?sort_by=best-selling&filter.v.availability=1&filter.v.m.my_fields.keycaps_profile=ASA+Profile&filter.v.m.my_fields.keycaps_profile=ASA-Low+Profile&filter.v.m.my_fields.keycaps_profile=CXA+Profile&filter.v.m.my_fields.keycaps_profile=Cherry+Profile&filter.v.m.my_fields.keycaps_profile=DCS+Profile&filter.v.m.my_fields.keycaps_profile=DSA+Profile&filter.v.m.my_fields.keycaps_profile=JDA+Profile&filter.v.m.my_fields.keycaps_profile=KAT+Profile&filter.v.m.my_fields.keycaps_profile=MA+Profile&filter.v.m.my_fields.keycaps_profile=MDA+Profile&filter.v.m.my_fields.keycaps_profile=NP+Profile&filter.v.m.my_fields.keycaps_profile=OEM+Profile&filter.v.m.my_fields.keycaps_profile=OSA+Profile&filter.v.m.my_fields.keycaps_profile=PG+Profile&filter.v.m.my_fields.keycaps_profile=SA+Profile&filter.v.m.my_fields.keycaps_profile=SAL+Profile&filter.v.m.my_fields.keycaps_profile=Tai-Hao+Cubic+Profile&filter.v.m.my_fields.keycaps_profile=XDA+Profile&filter.v.m.my_fields.keycaps_profile=特殊&filter.v.price.gte=&filter.v.price.lte=)|
|Type-C USB ケーブル|1|[遊舎工房](https://shop.yushakobo.jp/products/usb_type_a_to_c_cable?_pos=3&_sid=d2e0de26b&_ss=r)、[秋月電子通商](https://akizukidenshi.com/catalog/g/gC-13563/)、100円均一など|

### オプション
|部品名||
|-|-|
|アクリル積層ケース|[ケースデータと取り付け方法](CASE.md)|
 
### 必要な工具
|工具名|
|-|
|はんだごて|
|はんだ|
|精密ドライバー|
|ニッパー|

## 準備
<!-- 
### プレートを切り離す
メインボード、トッププレート、ボトムプレートを切り離します。そのまま折るだけでも割れますがカッターなどで切れ目を入れると入れる力が少なくて済みます。  
![](img/) 
ニッパーでバリを取り切断面を棒やすりで綺麗にします。  
![](img/)
-->
### 左右を決める
このキットは基板の表裏を変えることで左手用と右手用を作り分けることができます。   
![](img/IMG_2588.jpg) 
どちらの面にどの部品を実装するかが基板に書いてあるので参考にしてください。   

### XIAO RP2040にテストファームウェアを書き込む  
こちらのファイルをダウンロードしてください。  
- [tarohayashi_kombucha_stick_default.uf2](https://github.com/Taro-Hayashi/Kombucha2/releases/download/0.20.0/tarohayashi_kombucha_stick_default.uf2)

基板上の右のBのボタンを押しながらPCに接続するとRPI-RP2というドライブとして認識されます。  
![](img/IMG_2585.jpg) 
ダウンロードしたファイルを書き込むとXIAO RP2040をキーボードとして使えるようになります。  

## はんだ付け
### ボトムプレートのはんだ付け
左右を確認してボトムプレートにピンソケット2つをはんだ付けします。    
![](img/IMG_2591.jpeg) 
位置決めが難しい場合や使っているうちに剥がれた場合などはDIPタイプのピンソケットも使用することができます。  

ボトムプレートのピンソケットと同じ面にスペーサー（太）（短）をねじ（短）で止めます。黄丸の４箇所にはスペーサー（細）（長）を使います。  
![](img/IMG_2594.jpg) 
反対の面にはゴム足を貼ります。  
![](img/IMG_2597.jpeg) 

### ジョイスティック基板のはんだ付け
ジョイスティック基板にジョイスティックをはんだ付けします。  
![](img/IMG_2601.jpeg) 
ジョイスティックが中央に戻らないことがありますが、アクリルプレートを取り付ける前の正常な動作です。  

ボトムプレートのピンソケットに5ピンヘッダを立てます。短い方を差しました。  
![](img/IMG_2603.jpeg) 

ジョイスティック基板をスペーサー（細）（長）の上にのせ、スペーサー（太）（長）でボトムプレートに固定します。  
![](img/IMG_2604.jpeg) 

飛び出たピンヘッダをニッパーで切りはんだ付けしましょう（ギリギリまで切りすぎるとうまくはんだ付けできないことがあります）。   
![](img/IMG_2608.jpeg) 

ジョイスティックにキャップを取り付けます。  
![](img/IMG_2612.jpeg) 

### メインボードのはんだ付け
LEDをはんだ付けします。欠けている方向と白い線が合うように置きます。  
![](img/IMG_2618.jpg)   

XIAO RP2040を7ピンヘッダーではんだ付けします。  
![](img/IMG_2626.jpeg) 

USBケーブルを接続してLEDが発光することを確かめてください。光らない場合は向きが間違っていたりどこかでショートしていたりはんだ付けが足りない可能性があります。  
![](img/IMG_2624.jpeg)  
  
USBケーブルを抜いてください。はんだ付けの作業は通電していない状態で行います。  
この後も部品を取り付けるごとにその部品の動作を確認するとトラブルの原因を突き止めやすいです。   
    
ダイオードを折り曲げて差し込み、固定するためにさらに曲げます。表裏を指定してありますがどちら側でも構いません。  
![](img/IMG_2633.jpg) 
ダイオードには向きがあるので、黒線と基板の矢印の向きを合わせてください。  

はんだ付けをしたら足をニッパーで切ります。  
![](img/IMG_2635.jpeg) 

スイッチソケットをはんだ付けします。裏表に注意してください。  
![](img/IMG_2636.jpeg) 

メインボードにホイールエンコーダーとタクタイルスイッチ（足が下に伸びている方）をはんだ付けします。表裏に注意してください。  
![](img/IMG_2640.jpeg) 

ボトムプレートに7ピンヘッダを差し込みます。  
![](img/IMG_2641.jpeg) 

ボトムプレートにメインボードを載せ、スペーサー（太）（長）でボトムプレートに固定します。トッププレートで隠れる黄丸の一箇所だけはねじ（短）で止めます。  
![](img/IMG_2643.jpg) 
飛び出たピンヘッダをニッパーで切ってはんだ付けしましょう。テストファームウェアではジョイスティックは動作しません。  

トッププレートの4隅にスイッチを差し込みます。差し込みが硬い場合はここですべてのスイッチを固定してしまう方がいいかもしれません（スイッチの種類によって変わります）。  
![](img/IMG_2646.jpeg) 

スペーサーを通してメインボードに乗せ、キースイッチがスイッチソケットに入るように押し込みます。  
![](img/IMG_2648.jpeg) 
キースイッチのピンが曲がらないように気をつけてください。  

全てのスイッチを差し込み、ホイールをホイールエンコーダーに差し込みます。  
![](img/IMG_2652.jpeg) 

アクリルプレートから保護フィルムを剥がして、ねじ（長）で止めます。  
![](img/IMG_2990.jpeg) 

キーキャップをつけて完成です。
![](img/IMG_2994.jpeg) 
こちらのファームウェアを書き込んでください。XIAO RP2040のBのスイッチを押す代わりに、XIAO RP2040に一番近いキーを押しながらUSBケーブルを繋ぐことでRPI-RP2のドライブを出すことが出来ます。  
- [tarohayashi_kombucha_stick_stick.uf2](https://github.com/Taro-Hayashi/Kombucha2/releases/download/0.20.0/tarohayashi_kombucha_stick_stick.uf2)
  

## カスタマイズ
LEDを消したい時は親指クラスタ（最下段）の奥のキーを押しながらジョイスティックを押し込んでください。  
![](img/IMG_2994E.jpg) 

ジョイスティックを含めた全てのキーはVIAというWebサイト（もしくはアプリケーション）で好きなものに変更することができます。  
こちらのJSONファイルをダウンロードしてください。 
- [kombucha.json](https://github.com/Taro-Hayashi/Kombucha2/releases/download/0.20.0/kombucha.json)

Google Chrome（Microsoft Edge）を利用して下記webサイトにアクセスするか、VIAのアプリケーションをダウンロードして起動してください。  
- [Web版VIA（Google Chromeでアクセスしてください）](https://usevia.app/#/design)
- [アプリ版VIA](https://github.com/the-via/releases/releases)

DESIGNタブのLoadでダウンロードしたJSONファイルを読み込ませるとキーの変更が出来るようになります（アプリ版ではまずShow Design tabをオンにしてください）。  
![](img/VIA_load.jpeg)  
CONFIGUREタブのAuthorize device+からKombuchaを追加してください。  

### 左右の変更
LAYOUTSから見た目の左右を変更することができます。  
![](img/VIA_layout.jpeg)  

### ホイールの割り当てキー
キーマップ変更画面で上部の丸をクリックするとホイールを回転させた時と押し込んだ時に入力されるキーを変更することができます。  
![](img/VIA_wheel.jpeg)  

### その他の利用方法
ジョイスティックでマウスカーソルを動かすことも可能で、その場合はこちらのファイルをダウンロードしてファームウェアを書き換えてください。 
- 左手用 [tarohayashi_kombucha_stick_cursor_left.uf2](https://github.com/Taro-Hayashi/Kombucha2/releases/download/0.20.0/tarohayashi_kombucha_stick_cursor_left.uf2)
- 右手用 [tarohayashi_kombucha_stick_cursor_right.uf2](https://github.com/Taro-Hayashi/Kombucha2/releases/download/0.20.0/tarohayashi_kombucha_stick_cursor_right.uf2)

こちらのファームウェアを書き込むことでKombuchaをゲームパッドとして認識させることもできます。  
- 左手用 [tarohayashi_kombucha_stick_joypad_left.uf2](https://github.com/Taro-Hayashi/Kombucha2/releases/download/0.20.0/tarohayashi_kombucha_stick_joypad_left.uf2)
- 右手用 [tarohayashi_kombucha_stick_joypad_right.uf2](https://github.com/Taro-Hayashi/Kombucha2/releases/download/0.20.0/tarohayashi_kombucha_stick_joypad_right.uf2)

ジョイスティックを傾けない時の軸ズレ、軸ブレが気になる場合はこちらのファームウェアをお試しください。
- [tarohayashi_kombucha_sitck_joypad_fix.uf2](https://github.com/Taro-Hayashi/Kombucha2/releases/download/0.20.0/tarohayashi_kombucha_stick_joypad_fix.uf2)
  
LEDレイヤーのホイールクリックでジョイスティックの方向を変更できます。

#### ジョイスティックの補正
WindowsではスタートメニューにJOY.CPLと打ち込むとスティックの補正ができます。  
![](img/joy1.png)   
プロパティから調整を選びウィザードに従ってください。  
![](img/joy2png.png)    
上手く動かない場合はゲームパッドとしてではなく通常のファームウェアにカーソルキーやWASDを割り当ててお使いください。  

## meishi Trackball Moduleを使う
### はんだ付け
一度分解し、ボトムプレートにタクタイルスイッチSMDをはんだ付けします。
![](img/IMG_2830.jpeg)  
ピンヘッダーが有る側の2箇所はスペーサー（細）（長）、無い側の2箇所はスペーサー（細）（短）をねじ止めします。
![](img/IMG_2832.jpg) 
meishi Trackball Module互換基板キットを使う場合は袋の番号を確認しながら部品をはんだ付けします。使わない場合はmeishi Trackball Moduleを基板から切り離してください。
![](img/IMG_2885.jpeg)  
抵抗やコンデンサーは小袋から出すと見分けが付かなくなるので1種類ずつはんだ付けしてください。
![](img/IMG_2886.jpeg)  
LEDをはんだ付けします。
![](img/IMG_2888.jpeg)  
センサーをはんだ付けします。
![](img/IMG_2890.jpeg)  
ジョイスティックの時と同様にピンヘッダを立てモジュール付属のねじを使って基板の位置を決めたらはんだ付けします。
![](img/IMG_2834.jpeg)  
はんだ付けをしたらねじを一度はずしてモジュール基板を取り外し、センサーの保護フィルムをはがしてレンズとボールケースを取り付けます。  
![](img/IMG_2899.jpg)  
ピンヘッダーのない側にスペーサー（細）（短）をねじで止めます。  
  
スペーサーの上にスプリングを立てます。
![](img/IMG_2839.jpeg)
ねじでスペーサー（細）（長）側も止めるとボールのクリックができるようになります。
![](img/IMG_2842.jpeg)
組み立て直したら完成です。
![](img/IMG_3114.jpeg)

ファームウェアはこちらをお使いください。  
- [tarohayashi_kombucha_ball_via.uf2](https://github.com/Taro-Hayashi/Kombucha2/releases/download/0.20.0/tarohayashi_kombucha_ball_via.uf2)

### トラックボールの調整
親指クラスタの真ん中のキーを押しながらボールの左右のキーを押すとセンサーの感度（CPI）を増減できます。その下のキーを押すとマウスカーソルの上下左右の十字方向と10°の微調整が可能です。
![](img/IMG_3114E.jpg)

## その他
### ファームウェアのフォルダ（QMK 0.20.0以降）
- https://github.com/Taro-Hayashi/qmk_firmware/tree/tarohayashi/keyboards/tarohayashi/kombucha

### ファームウェアまとめ
- テスト用 [tarohayashi_kombucha_stick_default.uf2](https://github.com/Taro-Hayashi/Kombucha2/releases/download/0.20.0/tarohayashi_kombucha_stick_default.uf2)
- スティックにキー割り当て [tarohayashi_kombucha_stick_stick.uf2](https://github.com/Taro-Hayashi/Kombucha2/releases/download/0.20.0/tarohayashi_kombucha_stick_stick.uf2)
- マウスカーソル左手用 [tarohayashi_kombucha_stick_cursor_left.uf2](https://github.com/Taro-Hayashi/Kombucha2/releases/download/0.20.0/tarohayashi_kombucha_stick_cursor_left.uf2)
- マウスカーソル右手用 [tarohayashi_kombucha_stick_cursor_right.uf2](https://github.com/Taro-Hayashi/Kombucha2/releases/download/0.20.0/tarohayashi_kombucha_stick_cursor_right.uf2)
- ジョイパッド左手用 [tarohayashi_kombucha_stick_joypad_left.uf2](https://github.com/Taro-Hayashi/Kombucha2/releases/download/0.20.0/tarohayashi_kombucha_stick_joypad_left.uf2)
- ジョイパッド右手用 [tarohayashi_kombucha_stick_joypad_right.uf2](https://github.com/Taro-Hayashi/Kombucha2/releases/download/0.20.0/tarohayashi_kombucha_stick_joypad_right.uf2)
- ジョイパッド軸補正[tarohayashi_kombucha_sitck_joypad_fix.uf2](https://github.com/Taro-Hayashi/Kombucha2/releases/download/0.20.0/tarohayashi_kombucha_stick_joypad_fix.uf2)
- トラックボール [tarohayashi_kombucha_ball_via.uf2](https://github.com/Taro-Hayashi/Kombucha2/releases/download/0.20.0/tarohayashi_kombucha_ball_via.uf2)

### VIA用JSON
- [kombucha.json](https://github.com/Taro-Hayashi/Kombucha2/releases/download/0.20.0/kombucha.json)

### アクリルプレートのデータ
DXF、SVG、kicadファイルが入っています。
- [kombucha_acrylic_case_elecrow.zip](https://github.com/Taro-Hayashi/Kombucha2/releases/download/0.19.12%2Fdevelop/kombucha_acrylic_case_elecrow.zip)

### 謝辞
aki27さんのコードを参考にトラックボール用のファームウェアを書きました。
- URL　https://github.com/aki27kbd/qmk_firmware
- ライセンス https://github.com/aki27kbd/qmk_firmware/blob/master/LICENSE

### 販売サイト  
- BOOTH: https://tarohayashi.booth.pm/items/3252673 
