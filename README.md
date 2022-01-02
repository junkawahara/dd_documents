# ZDD の実装に関する情報

Zero-suppressed binary decision diagram (ZDD) を始めとする決定グラフ（DD）の処理系に関する情報を提供するページです。

## 目的別ナビゲーション

* DD のアルゴリズムや実装の中身を知らずに、集合族の圧縮や、部分グラフ列挙を行いたい。

→ [graphillion](https://github.com/takemaru/graphillion) を用いるのがお勧めです。以下の「graphillion 情報」のページを参考にしてください。

* DD を用いたアルゴリズムの実装を行いたい。

→ [SAPPOROBDD](https://github.com/Shin-ichi-Minato/SAPPOROBDD) & [TdZdd](https://github.com/kunisura/TdZdd) によって可能です。以下の「SAPPOROBDD & TdZdd 情報」のページを参考にしてください。

## graphillion 情報

[graphillion](https://github.com/takemaru/graphillion) は集合族や部分グラフ集合を圧縮して活用するための Python ライブラリです。

公式サイトに詳しいドキュメントがあります（[英語版](https://github.com/takemaru/graphillion)、[日本語版](https://github.com/takemaru/graphillion/wiki)）。

[graphillion のチュートリアル](https://github.com/nsnmsak/graphillion_tutorial) を読むのもお勧めです。

## SAPPOROBDD & TdZdd 情報

DD に関する概要は、書籍「[超高速グラフ列挙アルゴリズム－〈フカシギの数え方〉が拓く，組合せ問題への新アプローチ－](https://www.morikita.co.jp/books/mid/085261)」や、[フロンティア法解説講演資料](https://www.algo.cce.i.kyoto-u.ac.jp/jkawahara/frontier/)を参考にしてください。[英語論文 (pdf)](https://www-alg.ist.hokudai.ac.jp/~thomas/TCSTR/tcstr_14_76/tcstr_14_76.pdf) もあります。

DD を用いたアルゴリズムの実装を始めるには、[dd_package](https://github.com/junkawahara/dd_package) が便利です。このパッケージでは、SAPPOROBDD や TdZdd、いくつか便利なライブラリをまとめてインストールできます。

SAPPOROBDD について最初に読むドキュメントとして[DDライブラリ入門](dd_library_inst.pdf) があります。TdZdd は[解説論文](https://www.jstage.jst.go.jp/article/jssst/34/3/34_3_97/_article/-char/ja/) があります。以下の公式マニュアルがあります。

* [SAPPOROBDD マニュアル](https://github.com/Shin-ichi-Minato/SAPPOROBDD/raw/main/man/BDD%2B.pdf) パッケージの SAPPOROBDD/man/BDD+.pdf に入っています。
* [SAPPOROBDD helper マニュアル](https://github.com/junkawahara/sbdd_helper)
* [TdZdd ユーザガイド（英語）](http://kunisura.github.io/TdZdd/doc/index.html)

フロンティア法の実装のサンプルコードは [frontier_basic_tdzdd](https://github.com/junkawahara/frontier_basic_tdzdd) にあります。

[DDの再帰演算のカタログ](dd_recur_function.pdf)に、各種再帰演算の SAPPOROBDD でのコード例が掲載されています。


## その他ドキュメント

* [BDD バイナリ形式](formats/bdd_binary_format.md)
* [graphillion 形式](formats/graphillion_format.md)
* [TdZdd の Graph クラスについて](formats/tdzdd_graph_ja.md)
* [Graph class in the TdZdd library](formats/tdzdd_graph_en.md)

## その他リンク集

* [TdZdd を用いたネットワーク信頼性計算](https://github.com/junkawahara/reliability_tdzdd)
* [dd_converter (TdZdd と graphillion 形式の相互変換)](https://github.com/junkawahara/dd_converter)

