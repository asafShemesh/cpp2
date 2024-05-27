// 325362457   asaf0604@gmail.com
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <stdexcept>
#include <iostream>

namespace ariel {
    class Graph {
    public:
        Graph();

        void loadGraph(const std::vector<std::vector<int>>& matrix);
        void printGraph() const;
        const std::vector<std::vector<int>>& getAdjacencyMatrix() const;
        size_t getNumVertices() const;
        size_t getNumEdges() const;
        int getValue(size_t row, size_t col) const;

        Graph operator+(const Graph& other) const;
        Graph& operator+=(const Graph& other);
        Graph operator+() const; 

        Graph operator-(const Graph& other) const;
        Graph& operator-=(const Graph& other);
        Graph operator-() const; 

        Graph& operator++();    
        Graph operator++(int); 
        Graph& operator--();   
        Graph operator--(int);  

        Graph operator*(int scalar) const;
        Graph& operator*=(int scalar);

        Graph operator/(int scalar) const;
        Graph& operator/=(int scalar);

        Graph operator*(const Graph& other) const;

        bool operator==(const Graph& other) const;
        bool operator!=(const Graph& other) const;
        bool operator>(const Graph& other) const;
        bool operator>=(const Graph& other) const;
        bool operator<(const Graph& other) const;
        bool operator<=(const Graph& other) const;

        bool contains(const Graph& other) const;

        friend std::ostream& operator<<(std::ostream& os, const Graph& graph);

    private:
        std::vector<std::vector<int>> adjacencyMatrix;

        void checkDimensions(const Graph& other) const;
        size_t getEdgeCount() const;
        int getOrderOfMagnitude() const;
    };
}

#endif
