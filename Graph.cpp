// 325362457   asaf0604@gmail.com
#include "Graph.hpp"
#include <stdexcept>
#include <algorithm>
#include <iostream>

namespace ariel
{
    Graph::Graph() {}

    void Graph::loadGraph(const std::vector<std::vector<int>> &matrix)
    {
        size_t size = matrix.size();
        for (const auto &row : matrix)
        {
            if (row.size() != size)
            {
                throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
            }
        }
        adjacencyMatrix = matrix;
    }

    void Graph::printGraph() const
    {
        std::cout << "Graph with " << adjacencyMatrix.size() << " vertices and ";
        int edges = getNumEdges();
        std::cout << edges << " edges." << std::endl;

        for (const auto &row : adjacencyMatrix)
        {
            for (int value : row)
            {
                std::cout << value << " ";
            }
            std::cout << std::endl;
        }
    }

    const std::vector<std::vector<int>> &Graph::getAdjacencyMatrix() const
    {
        return adjacencyMatrix;
    }

    size_t Graph::getNumVertices() const
    {
        return adjacencyMatrix.size();
    }

    size_t Graph::getNumEdges() const
    {
        size_t edges = 0;
        for (size_t i = 0; i < adjacencyMatrix.size(); ++i)
        {
            for (size_t j = i; j < adjacencyMatrix[i].size(); ++j)
            {
                if (adjacencyMatrix[i][j] != 0)
                {
                    edges++;
                }
            }
        }
        return edges;
    }

    int Graph::getValue(size_t row, size_t col) const
    {
        if (row >= adjacencyMatrix.size() || col >= adjacencyMatrix.size())
        {
            throw std::out_of_range("Invalid indices.");
        }
        return adjacencyMatrix[row][col];
    }

    void Graph::checkDimensions(const Graph &other) const
    {
        if (adjacencyMatrix.size() != other.adjacencyMatrix.size())
        {
            throw std::invalid_argument("Graph dimensions must match");
        }
    }

    Graph Graph::operator+(const Graph &other) const
    {
        checkDimensions(other);
        Graph result;
        result.adjacencyMatrix = adjacencyMatrix;
        for (size_t i = 0; i < adjacencyMatrix.size(); ++i)
        {
            for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j)
            {
                result.adjacencyMatrix[i][j] += other.adjacencyMatrix[i][j];
            }
        }
        return result;
    }

    Graph &Graph::operator+=(const Graph &other)
    {
        checkDimensions(other);
        for (size_t i = 0; i < adjacencyMatrix.size(); ++i)
        {
            for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j)
            {
                adjacencyMatrix[i][j] += other.adjacencyMatrix[i][j];
            }
        }
        return *this;
    }

    Graph Graph::operator+() const
    {
        Graph result;
        result.adjacencyMatrix = adjacencyMatrix;
        for (auto &row : result.adjacencyMatrix)
        {
            for (auto &elem : row)
            {
                if (elem < 0)
                {
                    elem = -elem;
                }
            }
        }
        return result;
    }

    Graph Graph::operator-(const Graph &other) const
    {
        checkDimensions(other);
        Graph result;
        result.adjacencyMatrix = adjacencyMatrix;
        for (size_t i = 0; i < adjacencyMatrix.size(); ++i)
        {
            for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j)
            {
                result.adjacencyMatrix[i][j] -= other.adjacencyMatrix[i][j];
            }
        }
        return result;
    }

    Graph &Graph::operator-=(const Graph &other)
    {
        checkDimensions(other);
        for (size_t i = 0; i < adjacencyMatrix.size(); ++i)
        {
            for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j)
            {
                adjacencyMatrix[i][j] -= other.adjacencyMatrix[i][j];
            }
        }
        return *this;
    }

    Graph Graph::operator-() const
    {
        Graph result;
        result.adjacencyMatrix = adjacencyMatrix;
        for (auto &row : result.adjacencyMatrix)
        {
            for (auto &elem : row)
            {
                elem = -elem;
            }
        }
        return result;
    }

    Graph &Graph::operator++()
    {
        for (auto &row : adjacencyMatrix)
        {
            for (auto &elem : row)
            {
                ++elem;
            }
        }
        return *this;
    }

    Graph Graph::operator++(int)
    {
        Graph temp = *this;
        ++(*this);
        return temp;
    }

    Graph &Graph::operator--()
    {
        for (auto &row : adjacencyMatrix)
        {
            for (auto &elem : row)
            {
                --elem;
            }
        }
        return *this;
    }

    Graph Graph::operator--(int)
    {
        Graph temp = *this;
        --(*this);
        return temp;
    }

    Graph Graph::operator*(int scalar) const
    {
        Graph result;
        result.adjacencyMatrix = adjacencyMatrix;
        for (auto &row : result.adjacencyMatrix)
        {
            for (auto &elem : row)
            {
                elem *= scalar;
            }
        }
        return result;
    }

    Graph &Graph::operator*=(int scalar)
    {
        for (auto &row : adjacencyMatrix)
        {
            for (auto &elem : row)
            {
                elem *= scalar;
            }
        }
        return *this;
    }

    Graph Graph::operator/(int scalar) const
    {
        if (scalar == 0)
        {
            throw std::invalid_argument("Division by zero.");
        }
        Graph result;
        result.adjacencyMatrix = adjacencyMatrix;
        for (auto &row : result.adjacencyMatrix)
        {
            for (auto &elem : row)
            {
                elem /= scalar;
            }
        }
        return result;
    }

    Graph &Graph::operator/=(int scalar)
    {
        if (scalar == 0)
        {
            throw std::invalid_argument("Division by zero.");
        }
        for (auto &row : adjacencyMatrix)
        {
            for (auto &elem : row)
            {
                elem /= scalar;
            }
        }
        return *this;
    }

    Graph Graph::operator*(const Graph &other) const
    {
        checkDimensions(other);
        Graph result;
        size_t n = adjacencyMatrix.size();
        result.adjacencyMatrix.resize(n, std::vector<int>(n, 0));
        for (size_t i = 0; i < n; ++i)
        {
            for (size_t j = 0; j < n; ++j)
            {
                for (size_t k = 0; k < n; ++k)
                {
                    result.adjacencyMatrix[i][j] += adjacencyMatrix[i][k] * other.adjacencyMatrix[k][j];
                }
            }
        }
        return result;
    }

    bool Graph::operator==(const Graph &other) const
    {
        return adjacencyMatrix == other.adjacencyMatrix;
    }

    bool Graph::operator!=(const Graph &other) const
    {
        return !(*this == other);
    }

    bool Graph::operator>(const Graph &other) const
    {
        if (contains(other))
        {
            return true;
        }
        size_t edgeCount1 = getNumEdges();
        size_t edgeCount2 = other.getNumEdges();
        if (edgeCount1 != edgeCount2)
        {
            return edgeCount1 > edgeCount2;
        }
        return getOrderOfMagnitude() > other.getOrderOfMagnitude();
    }

    bool Graph::operator>=(const Graph &other) const
    {
        return *this > other || *this == other;
    }

    bool Graph::operator<(const Graph &other) const
    {
        return !(*this >= other);
    }

    bool Graph::operator<=(const Graph &other) const
    {
        return *this < other || *this == other;
    }

    int Graph::getOrderOfMagnitude() const
    {
        int sum = 0;
        for (const auto &row : adjacencyMatrix)
        {
            for (int value : row)
            {
                sum += value;
            }
        }
        return sum;
    }

    bool Graph::contains(const Graph &other) const
    {
        if (adjacencyMatrix.size() != other.adjacencyMatrix.size())
        {
            return false;
        }
        for (size_t i = 0; i < adjacencyMatrix.size(); ++i)
        {
            for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j)
            {
                if (adjacencyMatrix[i][j] < other.adjacencyMatrix[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }

    std::ostream &operator<<(std::ostream &os, const Graph &graph)
    {
        for (const auto &row : graph.adjacencyMatrix)
        {
            for (const auto &elem : row)
            {
                os << elem << " ";
            }
            os << std::endl;
        }
        return os;
    }
}
