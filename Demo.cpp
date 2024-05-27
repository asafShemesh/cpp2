// 325362457   asaf0604@gmail.com
#include "Graph.hpp"
using ariel::Graph;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main() {
    ariel::Graph g1;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph); // Load the graph to the object.

    g1.printGraph(); // Should print the matrix of the graph: [0, 1, 0], [1, 0, 1], [0, 1, 0]

    // 3x3 matrix that represents a weighted connected graph.
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    ariel::Graph g2;
    g2.loadGraph(weightedGraph); // Load the graph to the object.

    ariel::Graph g3 = g1 + g2; // Add the two graphs together.
    g3.printGraph();           // Should print the matrix of the graph: [0, 2, 1], [2, 0, 3], [1, 3, 0]

    g1 *= -2;        // Multiply the graph by -2.
    g1.printGraph(); // Should print the matrix of the graph: [0, -2, 0], [-2, 0, -2], [0, -2, 0]

    g1 /= -2;
    g1.printGraph(); // Should print the matrix of the graph: [0, 1, 0], [1, 0, 1], [0, 1, 0]

    ariel::Graph g4 = g1 * g2; // Multiply the two graphs together.
    g4.printGraph();           // Should print the multiplication of the matrices of g1 and g2: [1, 0, 2], [1, 3, 1], [1, 0, 2]

    ariel::Graph g5 = g2 - g1;
    g5.printGraph(); // Should print the matrix of the graph: [0, 0, 1], [0, 0, 1], [1, 1, 0]

    ++g1;
    g1.printGraph(); // Should print the matrix of the graph: [1, 2, 1], [2, 1, 2], [1, 2, 1]

    --g1;
    g1.printGraph(); // Should print the matrix of the graph: [0, 1, 0], [1, 0, 1], [0, 1, 0]

    ariel::Graph gNeg = -g1;
    gNeg.printGraph(); // Should print the matrix of the graph: [0, -1, 0], [-1, 0, -1], [0, -1, 0]

    bool contains = g2.contains(g1);
    cout << "g2 contains g1: " << (contains ? "true" : "false") << endl; // Should print: true

    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    ariel::Graph g6;
    g6.loadGraph(graph2); // Load the graph to the object.
    try {
        ariel::Graph g7 = g6 * g1; // Multiply the two graphs together.
    } catch (const std::invalid_argument &e) {
        cout << e.what() << endl; // Should print "Graph dimensions must match"
    }

    ariel::Graph g8 = g1 * 2;
    g8.printGraph(); // Should print the matrix of the graph: [0, 2, 0], [2, 0, 2], [0, 2, 0]

    ariel::Graph g9 = g8 / 2;
    g9.printGraph(); // Should print the matrix of the graph: [0, 1, 0], [1, 0, 1], [0, 1, 0]

    return 0;
}
