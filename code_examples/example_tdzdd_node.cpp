#include "tdzdd/DdSpec.hpp"
#include "tdzdd/DdStructure.hpp"

#include "tdzdd/spec/SizeConstraint.hpp"
#include "tdzdd/eval/ToZBDD.hpp"

using namespace tdzdd;

#include <queue>
#include <set>

int main() {

    // construct an example dd
    IntRange range(2, 2);
    SizeConstraint sc(3, range);
    DdStructure<2> dd(sc); // representing {{1, 2}, {1, 3}, {2, 3}}

    std::queue<NodeId> queue;
    std::set<NodeId> visited_nodes;
    NodeId node = dd.root(); // get the root node of dd

    visited_nodes.insert(node);
    queue.push(node);

    // visit all the nodes of dd (including the terminals)
    while (!queue.empty()) {
        node = queue.front();
        queue.pop();

        if (node.row() > 0) { // node is not a terminal node
            // node.row() is the level of node
            // node.col() is the node number in the level (0-origin)
            std::cout << node.row() << ":" << node.col() << std::endl;
        } else { // node is a terminal node
            // node.col() is the terminal number
            std::cout << node.col() << "-terminal" << std::endl;
        }

        NodeId child0 = dd.child(node, 0); // get the node pointed at by 0-arc of node
        NodeId child1 = dd.child(node, 1); // get the node pointed at by 1-arc of node

        if (visited_nodes.count(child0) == 0) { // child0 has not been visited yet
            visited_nodes.insert(child0);
            queue.push(child0);
        }
        if (visited_nodes.count(child1) == 0) { // child1 has not been visited yet
            visited_nodes.insert(child1);
            queue.push(child1);
        }
    }

    return 0;
}
