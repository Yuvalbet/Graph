/*
Email: yuvali532@gmail.com
*/
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Algorithms.hpp"
#include "BubbleSort.hpp"    
#include "Graph.hpp"
#include "PriorityQueue.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include "UnionFind.hpp"

using namespace graph;

TEST_CASE("Graph basic functionality") {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 3);
    g.addEdge(3, 0, 4);

    CHECK(g.getVertices() == 4);
    CHECK(g.getVertices() == 4);
}

TEST_CASE("BFS traversal") {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 3);

    Graph bfsTree = Algorithms::bfs(g, 0);
    CHECK(bfsTree.getVertices() == 4);
}

TEST_CASE("DFS traversal") {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 3);

    Graph dfsTree = Algorithms::dfs(g, 0);
    CHECK(dfsTree.getVertices() == 4);
}

TEST_CASE("Dijkstra algorithm") {
    Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 8);
    g.addEdge(3, 4, 4);

    Graph* dijkstraTree = Algorithms::dijkstra(g, 0);
    REQUIRE(dijkstraTree != nullptr);
    CHECK(dijkstraTree->getVertices() == 5);
    delete dijkstraTree;
}

TEST_CASE("Prim's algorithm") {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 3);
    g.addEdge(3, 0, 4);

    Graph mst = Algorithms::prim(g);
    CHECK(mst.getVertices() == 4);
}

TEST_CASE("Kruskal's algorithm") {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 3);
    g.addEdge(3, 0, 4);

    Graph mst = Algorithms::kruskal(g);
    CHECK(mst.getVertices() == 4);
}