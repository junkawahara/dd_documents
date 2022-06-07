# Graph class in the TdZdd library

This documents explains the usage of the [Graph class](https://github.com/kunisura/TdZdd/blob/master/include/tdzdd/util/Graph.hpp) in the [TdZdd](https://github.com/kunisura/TdZdd) library.

## Example of an input graph.

graph1.txt

```
Alice Bob
Bob Carol
Carol Dave
Dave Alice
Alice Carol
```

One line represents one edge. We separate the names of both endpoints with a space character.
The first line is edge number 0. The i-th line is edge number i+1.
The number of edges is obtained with the ``edgeSize()`` member function.

A vertex is represented by a string. In the example above, "Alice", "Bob", "Carol", and "Dave" are vertices.
Each vertex is given a "vertex number. The vertex number is a number between 1 and n.
Which vertex corresponds to which number is managed in the Graph class.
The `getVertex` member function can be used to get the vertex number corresponding to a vertex (string) (see example usage below).
The number of vertices is obtained with the ``vertexSize()`` member function.


## Example usage of the Graph class in TdZdd.

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

# Remark

Note that when reading a graph from a text file, the numbers in the text are not necessarily the vertex numbers of the graph.
For example, consider the following text file to be read.

```
0 1
0 2
1 2
```

This is a graph consisting of vertices "0", "1", and "2".
The Vertex numbers are NOT 0, 1, or 2. The vertex number must be obtained by e.g. `graph.getVertex("0")`.
(Vertex numbers 1, 2, and 3 are assigned to "0", "1" and "2", but which vertex number is assigned to which vertex is managed in the Graph class. It is necessary to check the correspondence by `getVertex`).
