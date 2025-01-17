# tdzdd のノードを取得する方法

* DdStructure<2>: DD の実体を表すクラス
* NodeId: DD のノードを表すクラス。比較可能
* dd.root(): dd の根ノードを取得する
* node.row(): node のレベルを取得する。0 の場合は終端
* node.col(): node の番号を取得する。レベルが 0 なら終端の番号を取得する。
* dd.child(node, i): node の i-枝側の子ノードを取得

[サンプルコード](code_examples/example_tdzdd_node.cpp)
