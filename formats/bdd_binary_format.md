# BDD バイナリ形式

本ドキュメントでは、BDD（Binary Decision Diagram）を扱うライブラリにおいて、BDD をバイナリ形式で入出力、
保持するための書式を定義する。
この書式を BDD バイナリ形式と呼ぶ。

本ドキュメントで扱う BDD バイナリ形式のバージョンは 1 である。

## BDD バイナリ形式で扱う BDD の種類

BDD バイナリ形式では、通常の BDD や ZDD（Zero-Suppressed Binary Decision Diagram）、MTBDD（終端の種類が2個より多い）、MDD（非終端ノードの arc の数が 2 個より多い）を扱う。これらを総称して単に BDD と呼ぶ。本 BDD バイナリ形式で扱う BDD は既約でなくてもよい。

## BDD バイナリ形式の構造

BDD バイナリ形式は「ヘッダ」と「本体」からなる。
それぞれについて以下で説明する。

## ヘッダ

先頭の3バイトは 0x42, 0x44, 0x44 である。
これは ASCII コードで 'B', 'D', 'D' である。
4バイト目からは以下のヘッダ構造を持つ。
C 言語風の構造体で示す。

```
struct BDDBinaryFormatHeader {
    uint8_t version; // バージョン番号。
    uint8_t type; // BDD の種類
    uint16_t number_of_arcs; // 非終端ノードが持つ arc の数
    uint32_t number_of_terminals; // 終端ノードの数
    uint8_t number_of_bits_for_level; // 1個のレベル数を表現するのに使用するビット数
    uint8_t number_of_bits_for_id; // 1個のノードを表現するのに使用するビット数
    uint8_t use_negative_arcs; // 否定枝を使用するか否か
    uint64_t max_level; // 最大レベル（ノードが持つ最も高いレベル）
    uint64_t number_of_roots; // 根ノードの数、すなわち、BDD の個数
    uint8_t reserved[64]; // 予約領域（将来的に使用）
};
```

各項目の意味は以下の通りである。

### version

書式のバージョン番号を表す。本ドキュメントで
定義している書式のバージョンは 1 である。

### type

BDD の種類を表す。現在のところ、以下を定義している。

* 1: BDD でも ZDD でもどちらに解釈しても良いことを意味する。
* 2: BDD
* 3: ZDD

### number_of_arcs

非終端ノードが持つ arc の数（分岐の数）を意味する。
2 以上の整数でなければならない。
BDD/ZDD では 2 である。

### number_of_terminals

終端ノードのラベルの範囲を意味する（平たく言うと、
終端ノードの種類数）。
number_of_terminals == t であるとき、
終端ノードの ID は 0,1,...,t-1 とする。

BDD/ZDD では 2 である（一般に 0-terminal, 1-terminal と呼ばれる）。

1-terminal のみを持つ ZDD が存在するが、
その場合の number_of_terminals も 2 である。

### number_of_bits_for_level

1個のレベル数を表現するのに使用するビット数。本バージョンでは使用しない。

### number_of_bits_for_id

1個のID（整数値）を表現するのに使用するビット数。

### use_negative_arcs

否定枝を使用する場合は 1、しない場合は 0。

現バージョンでは、否定枝を使用する場合、number_of_arcs と
number_of_terminals はともに 2 でなければならない。

### max_level

ノードが持つ最も高いレベル。1以上でなければならない。
レベルの説明も参照

### number_of_roots

根ノードの数、すなわち、BDD の個数。1以上でなければならない。
1の場合は1つの BDD を意味する。

### reserved

予約領域。本バージョンでは使用しない。将来のバージョンで使用する可能性がある。

## ノードのIDとレベル

BDD バイナリ形式の「本体」の説明の前に、ノードのIDと
レベルについて説明する。

ノードはIDと呼ばれる番号によって識別される。
b = number_of_bits_for_id, t = number_of_terminals と
すると、ノードIDは、t 以上、2^b 未満の整数である。

use_negative_arcs == 1 の場合、すなわち、否定枝を使用する
場合、ID の最右ビットによって否定枝を表す。すなわち、
ID が奇数の場合は否定枝であることを表す。
use_negative_arcs == 0 の場合はそのような制約は存在しない。

BDDはレベルを持つ。終端に近い方から順に 1,2,... とする。
最大値は max_level で指定される。

## 本体

ヘッダの後には本体が続く。本体は以下の構造を持つ。

```
各レベルのノードの個数を表す配列
根ノードのIDの配列
各ノードを表す配列
```

### 各レベルのノードの個数を表す配列

この配列では、各レベルのノードの個数を表す。
1レベルのノードの個数を uint64_t 整数1個で表す。
先頭から順にレベル1、レベル2、...、レベル max_level の
ノードの個数を表す。

### 根ノードのIDの配列

この配列では根ノードのIDを格納する。
根ノード 1 個あたり、number_of_bits_for_id で指定されるビット数が
使用される。根ノードの個数は number_of_roots で指定される。

### 各ノードを表す配列

k = number_of_arcs, t = number_of_terminals とする。
1個のノードは 0-arc が指すノードのID、
1-arc が指すノードのID、...、(k-1)-arc が指すノードのID からなる。
1個のノードを表す必要ビット数は k × number_of_bits_for_id である。
各ノードを表す配列は先頭から順にノードID t, t+1,... のノードを
格納する。
