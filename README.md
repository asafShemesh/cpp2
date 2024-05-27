# Task 1 - Graphs (Classes and Namespaces)
325362457 asaf0604@gmail.com

## Project Overview
This project implements various graph operations and algorithms in C++. It includes the implementation of the `Graph` class along with numerous graph operations and tests.

The `Graph` class contains functionalities to represent and work with graphs. These include:

## Methods

- **`loadGraph(const std::vector<std::vector<int>> &matrix)`**: 
  Loads the graph from the given adjacency matrix, ensuring it is a square matrix.

- **`printGraph() const`**: 
  Prints information about the graph, including the number of vertices and edges.

- **`getAdjacencyMatrix() const`**: 
  Returns the adjacency matrix of the graph.

- **`getNumVertices() const`**: 
  Returns the number of vertices in the graph.

- **`getNumEdges() const`**: 
  Returns the number of edges in the graph, counting each edge once for undirected graphs.

- **`getValue(size_t row, size_t col) const`**: 
  Returns the value at the specified position in the adjacency matrix, with bounds checking.

- **`contains(const Graph& other) const`**: 
  Checks if the current graph contains the other graph.

## Operators

- **Arithmetic Operators**: 
  - `operator+` and `operator+=`: Graph addition.
  - `operator-` and `operator-=`: Graph subtraction.
  - `operator-` (negation): Negates all values in the adjacency matrix.
  - `operator+` (positive): posite all values in the adjacency matrix.
  - `operator*` and `operator*=`: Scalar multiplication and graph multiplication.
  - `operator/` and `operator/=`: Scalar division.

- **Increment/Decrement Operators**: 
  - `operator++` and `operator++(int)`: Increment each value in the adjacency matrix.
  - `operator--` and `operator--(int)`: Decrement each value in the adjacency matrix.

- **Comparison Operators**: 
  - `operator==` and `operator!=`: Checks for equality and inequality.
  - `operator>`, `operator>=`, `operator<`, and `operator<=`: Compares graphs based on edge count and order of magnitude.


### List of Tests

- **Arithmetic Operators**:
  - `operator+`
  - `operator+=`
  - `operator-`
  - `operator-=`
  - `operator* (scalar multiplication)`
  - `operator*= (scalar multiplication)`
  - `operator/`
  - `operator/=`
  - `operator* (graph multiplication)`
  - `operator- (negation)`

- **Increment/Decrement Operators**:
  - `operator++ (prefix)`
  - `operator++ (postfix)`
  - `operator-- (prefix)`
  - `operator-- (postfix)`

- **Comparison Operators**:
  - `operator==`
  - `operator!=`
  - `operator>`
  - `operator>=`
  - `operator<`
  - `operator<=`

- **Contains Method**:
  - `contains`

## Makefile

To compile the program, run `make` and then execute `./demo` or `./test` accordingly.
