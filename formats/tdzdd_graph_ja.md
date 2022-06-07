# TdZdd の Graph クラスについて

このドキュメントでは、[TdZdd](https://github.com/kunisura/TdZdd) の [Graph クラス](https://github.com/kunisura/TdZdd/blob/master/include/tdzdd/util/Graph.hpp)の使い方を説明します。

## 入力グラフの例

graph1.txt テキストファイル

```
Alice Bob
Bob Carol
Carol Dave
Dave Alice
Alice Carol
```

1行で1つの辺を表す。両端点の名前を空白文字で区切る。
1行目が辺番号 0 になり、以下、i 行目が辺番号 i+1 になる。
辺の数は ```edgeSize()``` メンバ関数で得られる。

頂点は文字列で表される。上の例では、"Alice", "Bob", "Carol", "Dave" が頂点である。
各頂点には「頂点番号」が与えられる。頂点番号は 1 以上 n 以下の数であるが、
どの頂点がどの番号に対応するかは Graph クラス内で管理される。
`getVertex` メンバ関数で、頂点（文字列）に対応する頂点番号を取得できる（以下の使用例を参照）。
頂点数は ```vertexSize()``` メンバ関数で得られる。


## 使用例

```
#include <tdzdd/DdSpec.hpp>
#include <tdzdd/util/Graph.hpp>

using namespace tdzdd;

int main(int argc, char** argv) {

    Graph graph;

    // グラフを読み込む
    graph.readEdges("graph1.txt");

    // 頂点数
    std::cout << "The number of vertices = " << graph.vertexSize() << std::endl;
    // 辺数
    std::cout << "The number of edges = " << graph.edgeSize() << std::endl;

    // 頂点の名前を頂点番号に変換
    std::cout << "Alice" << ": " << graph.getVertex("Alice") << std::endl;
    std::cout << "Bob" << ": " << graph.getVertex("Bob") << std::endl;
    std::cout << "Carol" << ": " << graph.getVertex("Carol") << std::endl;
    std::cout << "Dave" << ": " << graph.getVertex("Dave") << std::endl;

    for (int v = 1; v <= graph.vertexSize(); ++v) {
        // 頂点番号を頂点の名前に変換
        std::cout << "vertex " << v << ": "
                  << graph.vertexName(v) << std::endl;
    }

    for (int i = 0; i < graph.edgeSize(); ++i) {
        // 辺番号 i の辺を取得
        const Graph::EdgeInfo& edge = graph.edgeInfo(i);
        // 辺の両端点の頂点番号は edge.v1 と edge.v2 で取得可能
        std::cout << "edge " << i << ": "
                  << "(" << edge.v1 << ", " << edge.v2 << ")" << std::endl;
    }

    return 0;
}
```

## 注意点

テキストファイルからグラフを読み込む際に、テキストに書かれた番号がグラフの頂点番号になるとは限らないことに注意。
例えば、以下のテキストファイルを読み込む場合を考える。

```
0 1
0 2
1 2
```

これは頂点 "0", "1", "2" からなるグラフであると考える。
頂点番号は 0, 1, 2 にはならない。頂点番号は `graph.getVertex("0")` などで取得する必要がある。
（頂点番号として 1,2,3 が割り振られるが、どの頂点がどの頂点番号になるかは Graph クラス内で管理しているので、`getVertex` で対応関係を調べる必要がある。）
