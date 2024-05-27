// 325362457   asaf0604@gmail.com
#include "doctest.h"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test operator+ function")
{
    ariel::Graph g1;
    ariel::Graph g2;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g1.loadGraph(graph1);
    g2.loadGraph(graph2);

    ariel::Graph g3 = g1 + g2;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    CHECK(g3.getAdjacencyMatrix() == expectedGraph);
}

TEST_CASE("Test unary + operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, -1, 0},
        {-1, 0, -1},
        {0, -1, 0}};
    g1.loadGraph(graph);

    ariel::Graph g2 = +g1;
    vector<vector<int>> expectedGraph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};

    CHECK(g2.getAdjacencyMatrix() == expectedGraph);
}

TEST_CASE("Test operator+= function")
{
    ariel::Graph g1;
    ariel::Graph g2;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g1.loadGraph(graph1);
    g2.loadGraph(graph2);

    g1 += g2;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    CHECK(g1.getAdjacencyMatrix() == expectedGraph);
}

TEST_CASE("Test operator- function")
{
    ariel::Graph g1;
    ariel::Graph g2;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g1.loadGraph(graph1);
    g2.loadGraph(graph2);

    ariel::Graph g3 = g1 - g2;
    vector<vector<int>> expectedGraph = {
        {0, 0, -1},
        {0, 0, -1},
        {-1, -1, 0}};
    CHECK(g3.getAdjacencyMatrix() == expectedGraph);
}

TEST_CASE("Test operator-= function")
{
    ariel::Graph g1;
    ariel::Graph g2;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g1.loadGraph(graph1);
    g2.loadGraph(graph2);

    g1 -= g2;
    vector<vector<int>> expectedGraph = {
        {0, 0, -1},
        {0, 0, -1},
        {-1, -1, 0}};
    CHECK(g1.getAdjacencyMatrix() == expectedGraph);
}

TEST_CASE("Test operator- (negation) function")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    ariel::Graph gNeg = -g1;
    vector<vector<int>> expectedGraph = {
        {0, -1, 0},
        {-1, 0, -1},
        {0, -1, 0}};
    CHECK(gNeg.getAdjacencyMatrix() == expectedGraph);
}

TEST_CASE("Test operator++ function (prefix)")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    ++g1;
    vector<vector<int>> expectedGraph = {
        {1, 2, 1},
        {2, 1, 2},
        {1, 2, 1}};
    CHECK(g1.getAdjacencyMatrix() == expectedGraph);
}

TEST_CASE("Test operator++ function (postfix)")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    g1++;
    vector<vector<int>> expectedGraph = {
        {1, 2, 1},
        {2, 1, 2},
        {1, 2, 1}};
    CHECK(g1.getAdjacencyMatrix() == expectedGraph);
}

TEST_CASE("Test operator-- function (prefix)")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {1, 2, 1},
        {2, 1, 2},
        {1, 2, 1}};
    g1.loadGraph(graph);

    --g1;
    vector<vector<int>> expectedGraph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    CHECK(g1.getAdjacencyMatrix() == expectedGraph);
}

TEST_CASE("Test operator-- function (postfix)")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {1, 2, 1},
        {2, 1, 2},
        {1, 2, 1}};
    g1.loadGraph(graph);

    g1--;
    vector<vector<int>> expectedGraph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    CHECK(g1.getAdjacencyMatrix() == expectedGraph);
}

TEST_CASE("Test operator* function (scalar multiplication)")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    ariel::Graph g2 = g1 * 2;
    vector<vector<int>> expectedGraph = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    CHECK(g2.getAdjacencyMatrix() == expectedGraph);
}

TEST_CASE("Test operator*= function (scalar multiplication)")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    g1 *= 2;
    vector<vector<int>> expectedGraph = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    CHECK(g1.getAdjacencyMatrix() == expectedGraph);
}

TEST_CASE("Test operator/ function (scalar division)")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    g1.loadGraph(graph);

    ariel::Graph g2 = g1 / 2;
    vector<vector<int>> expectedGraph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    CHECK(g2.getAdjacencyMatrix() == expectedGraph);
}

TEST_CASE("Test operator/= function (scalar division)")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    g1.loadGraph(graph);

    g1 /= 2;
    vector<vector<int>> expectedGraph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    CHECK(g1.getAdjacencyMatrix() == expectedGraph);
}

TEST_CASE("Test operator* function (graph multiplication)")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(graph2);

    ariel::Graph g3 = g1 * g2;
    vector<vector<int>> expectedGraph = {
        {1, 0, 2},
        {1, 3, 1},
        {1, 0, 2}};
    CHECK(g3.getAdjacencyMatrix() == expectedGraph);
}

TEST_CASE("Test operator== function")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    ariel::Graph g2;
    g2.loadGraph(graph);

    CHECK(g1 == g2);
}

TEST_CASE("Test operator!= function")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(graph2);

    CHECK(g1 != g2);
}

TEST_CASE("Test operator> function")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(graph2);

    CHECK(g2 > g1);
}

TEST_CASE("Test operator>= function")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(graph2);

    CHECK(g2 >= g1);
}

TEST_CASE("Test operator< function")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(graph2);

    CHECK(g1 < g2);
}

TEST_CASE("Test operator<= function")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(graph2);

    CHECK(g1 <= g2);
}

TEST_CASE("Test contains function")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(graph2);

    CHECK(g1.contains(g2));
}
