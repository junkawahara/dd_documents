# TdZdd の Graph クラスについて

このドキュメントでは、[TdZdd](https://github.com/kunisura/TdZdd) の Graph クラスの使い方を説明します。

入力グラフの例

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

Graph クラスでは各頂点に「頂点番号」が振られる。
テキストファイルから読み込んだグラフの頂点の名前が
数字の場合、その数字がグラフの「頂点番号」になるとは
限らないことに注意。頂点番号は、「フロンティアから去る」
順に付けられる。頂点番号は 1 から始まり、
1,2,...,n の順に付けられる。n は頂点数であり、
```vertexSize()``` メンバ関数で得られる。


使用例

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
