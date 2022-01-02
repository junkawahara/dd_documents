# Graph class in the TdZdd library

This documents explains the usage of the Graph class in the [TdZdd](https://github.com/kunisura/TdZdd) library.
An explanation is under construction.

An example of an input graph.

graph1.txt

```
Alice Bob
Bob Carol
Carol Dave
Dave Alice
Alice Carol
```

An example usage of the Graph class in TdZdd.

```
#include <tdzdd/DdSpec.hpp>
#include <tdzdd/util/Graph.hpp>

using namespace tdzdd;

int main(int argc, char** argv) {

    Graph graph;

    // read a graph from a file
    graph.readEdges("graph1.txt");

    std::cout << "The number of vertices = " << graph.vertexSize() << std::endl;
    std::cout << "The number of edges = " << graph.edgeSize() << std::endl;

    // translate a vertex name to its vertex number
    std::cout << "Alice" << ": " << graph.getVertex("Alice") << std::endl;
    std::cout << "Bob" << ": " << graph.getVertex("Bob") << std::endl;
    std::cout << "Carol" << ": " << graph.getVertex("Carol") << std::endl;
    std::cout << "Dave" << ": " << graph.getVertex("Dave") << std::endl;

    for (int v = 1; v <= graph.vertexSize(); ++v) {
        // translate a vertex number to its vertex name
        std::cout << "vertex " << v << ": "
                  << graph.vertexName(v) << std::endl;
    }

    for (int i = 0; i < graph.edgeSize(); ++i) {
        // get the edge with edge number i
        const Graph::EdgeInfo& edge = graph.edgeInfo(i);
        // The endpoints of "edge" are edge.v1 and edge.v2.
        std::cout << "edge " << i << ": "
                  << "(" << edge.v1 << ", " << edge.v2 << ")" << std::endl;
    }

    return 0;
}
```
