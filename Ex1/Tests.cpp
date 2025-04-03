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

// 1. **Graph Tests**:
TEST_CASE("Graph basic functionality") {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 3);
    g.addEdge(3, 0, 4);

    CHECK(g.getVertices() == 4);

    // Add more edges and check the edge count
    g.addEdge(0, 2, 5);
    
    g.removeEdge(0, 1);
    CHECK(g.getVertices() == 4);
}
//!!להוסיף בדיקות על כל הפונקציות לדוגמא צלע חד כיוונית

TEST_CASE("Graph: Add self-loop") {
    Graph g(4);
    g.addEdge(0, 0, 1);  // Self loop
    CHECK(g.getVertices() == 4);
}

// 2. **BFS Tests**:
TEST_CASE("Graph: BFS traversal") {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 3);

    Graph bfsTree = Algorithms::bfs(g, 0);
    CHECK(bfsTree.getVertices() == 4);
}

// 3. **DFS Tests**:
TEST_CASE("Graph: DFS traversal") {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 3);

    Graph dfsTree = Algorithms::dfs(g, 0);
    CHECK(dfsTree.getVertices() == 4);
}

// 4. **Dijkstra's Algorithm Tests**:
TEST_CASE("Graph: Dijkstra algorithm") {
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

// 5. **Prim's Algorithm Tests**:
TEST_CASE("Graph: Prim's algorithm") {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 3);
    g.addEdge(3, 0, 4);

    Graph mst = Algorithms::prim(g);
    CHECK(mst.getVertices() == 4);
}

// 6. **Kruskal's Algorithm Tests**:
TEST_CASE("Graph: Kruskal's algorithm") {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 3);
    g.addEdge(3, 0, 4);

    Graph mst = Algorithms::kruskal(g);
    CHECK(mst.getVertices() == 4);
}

// 7. **Union-Find Tests**:
TEST_CASE("UnionFind find and union operations") {
    UnionFind uf(5);

    uf.unionSets(0, 1);
    uf.unionSets(2, 3);
    uf.unionSets(1, 2);
    
    // Verify connected components
    CHECK(uf.find(0) == uf.find(3));  // They should be in the same component
    CHECK(uf.find(0) != uf.find(4));  // Different components
}

// 8. **Queue Tests**:
TEST_CASE("Queue operations") {
    Queue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    CHECK(q.dequeue() == 1);
    CHECK(q.dequeue() == 2);

    q.enqueue(4);
    q.enqueue(5);
    CHECK(q.dequeue() == 3);
    CHECK(q.dequeue() == 4);
    CHECK(q.dequeue() == 5);
    CHECK(q.isEmpty() == true);
}

// 9. **Stack Tests**:
TEST_CASE("Stack operations") {
    Stack s(5);

    s.push(1);
    s.push(2);
    s.push(3);
    CHECK(s.pop() == 3);
    CHECK(s.pop() == 2);

    s.push(4);
    s.push(5);
    CHECK(s.pop() == 5);
    CHECK(s.pop() == 4);
    CHECK(s.pop() == 1);
         
    CHECK(s.isEmpty() == true);
}

// 10. **PriorityQueue Tests**:
TEST_CASE("PriorityQueue operations") {
    PriorityQueue pq(5);

    pq.push(0, 10);
    pq.push(1, 5);
    pq.push(2, 15);
    pq.push(3, 7);

    CHECK(pq.pop() == 1);  // Priority 5
    CHECK(pq.pop() == 3);  // Priority 7
    CHECK(pq.pop() == 0);  // Priority 10
    CHECK(pq.pop() == 2);  // Priority 15
    CHECK(pq.isEmpty() == true);
}
