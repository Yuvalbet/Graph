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

    // Add more edges and check the edge count
    g.addEdge(0, 2, 5);
    
    g.removeEdge(0, 1);
    CHECK(g.getVertices() == 4);
}

TEST_CASE("Graph: Add self-loop") {
    Graph g(4);
    // Self loop
    g.addEdge(0, 0, 1);
    CHECK(g.getVertices() == 4);
}

//BFS Tests:
TEST_CASE("Graph: BFS traversal") {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 3);

    Graph bfsTree = Algorithms::bfs(g, 0);
    CHECK(bfsTree.getVertices() == 4);
}

//DFS Tests:
TEST_CASE("Graph: DFS traversal") {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 3);

    Graph dfsTree = Algorithms::dfs(g, 0);
    CHECK(dfsTree.getVertices() == 4);
}

//Dijkstra's Algorithm Tests:
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

TEST_CASE("Dijkstra: Handle negative weights") {
    Graph g(3);
    g.addEdge(0, 1, 4);        // positive
    g.addEdge(1, 2, -5);       // negative

    Graph* dijkstraResult = Algorithms::dijkstra(g, 0);
    
    // In case of negative weight, Dijkstra should return nullptr
    CHECK(dijkstraResult == nullptr);  // Make sure we check for nullptr here
    
    delete dijkstraResult;
}

TEST_CASE("Graph: Prim's algorithm") {
    Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 5);
    g.addEdge(1, 3, 20);
    g.addEdge(2, 3, 15);
    g.addEdge(3, 4, 30);

    // Create the MST using Prim's algorithm
    Graph mst = Algorithms::prim(g);
    int edgeCount = 0;
    Edge* edges = mst.getAllEdges(edgeCount);
    
    // Check that the number of edges in MST is correct
    CHECK(edgeCount == g.getVertices() - 1); // There should be exactly vertices - 1 edges in the MST

    delete[] edges;  // Free the allocated memory
}




TEST_CASE("Graph: Kruskal's algorithm") {
    Graph g(6); \
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 3);
    g.addEdge(3, 0, 4);

    // Running Kruskal's algorithm to generate the MST
    Graph mst = Algorithms::kruskal(g);
    // The number of vertices in the MST should be the same
    CHECK(mst.getVertices() == 6);

    // Check if the MST has exactly N-1 edges
    int edgeCount = 0;
    Edge* edges = mst.getAllEdges(edgeCount);

    // Ensure the MST has the correct number of edges (N-1)
    CHECK(edgeCount == 3);

    std::cout << "Edges in MST:" << std::endl;
    for (int i = 0; i < edgeCount; ++i) {
        std::cout << "Edge: " << edges[i].src << " -> " << edges[i].dest << " with weight " << edges[i].weight << std::endl;
    }

    // Free the allocated memory
    delete[] edges; 
}




//Union-Find Tests:
TEST_CASE("UnionFind find and union operations") {
    UnionFind uf(5);

    uf.unionSets(0, 1);
    uf.unionSets(2, 3);
    uf.unionSets(1, 2);
    
    // Verify connected components
    CHECK(uf.find(0) == uf.find(3));  // They should be in the same component
    CHECK(uf.find(0) != uf.find(4));  // Different components
}

//Queue Tests:
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

//Stack Tests:
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

//PriorityQueue Tests:
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

// Additional Tests for Graph Class
TEST_CASE("Graph: Add undirected edge") {
    Graph g(4);
    g.addEdge(0, 1, 5);  // Undirected edge between 0 and 1

    // Check neighbors of 0 and 1
    Node* neighbors0 = g.getNeighbors(0);
    Node* neighbors1 = g.getNeighbors(1);

    bool found0 = false, found1 = false;
    while (neighbors0) {
        if (neighbors0->id == 1) {
            found0 = true;
            break;
        }
        neighbors0 = neighbors0->next;
    }
    while (neighbors1) {
        if (neighbors1->id == 0) {
            found1 = true;
            break;
        }
        neighbors1 = neighbors1->next;
    }
    CHECK(found0);  // There should be an edge from 0 to 1
    CHECK(found1);  // There should be an edge from 1 to 0
}

TEST_CASE("Graph: Add one-way edge") {
    Graph g(4);
    g.addOneEdge(0, 1, 5);  // One-way edge from 0 to 1

    // Check neighbors of 0 and 1
    Node* neighbors0 = g.getNeighbors(0);
    Node* neighbors1 = g.getNeighbors(1);

    bool found0 = false, found1 = false;
    while (neighbors0) {
        if (neighbors0->id == 1) {
            found0 = true;
            break;
        }
        neighbors0 = neighbors0->next;
    }
    while (neighbors1) {
        if (neighbors1->id == 0) {
            found1 = true;
            break;
        }
        neighbors1 = neighbors1->next;
    }
    CHECK(found0);  // There should be an edge from 0 to 1
    CHECK(!found1); // There should be no edge from 1 to 0
}

TEST_CASE("Graph: Remove edge") {
    Graph g(4);
    g.addEdge(0, 1, 5);
    g.addEdge(1, 2, 3);
    g.addEdge(2, 3, 7);

    g.removeEdge(0, 1);  // Remove edge from 0 to 1

    Node* neighbors0 = g.getNeighbors(0);
    Node* neighbors1 = g.getNeighbors(1);

    bool found0 = false, found1 = false;
    while (neighbors0) {
        if (neighbors0->id == 1) {
            found0 = true;
            break;
        }
        neighbors0 = neighbors0->next;
    }
    while (neighbors1) {
        if (neighbors1->id == 0) {
            found1 = true;
            break;
        }
        neighbors1 = neighbors1->next;
    }
    CHECK(!found0);  // There should be no edge from 0 to 1
    CHECK(!found1);  // There should be no edge from 1 to 0
}

TEST_CASE("Graph: Get neighbors of a vertex") {
    Graph g(4);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(2, 3, 7);

    Node* neighbors0 = g.getNeighbors(0);
    Node* neighbors2 = g.getNeighbors(2);

    bool found1 = false, found2 = false;
    while (neighbors0) {
        if (neighbors0->id == 1) found1 = true;
        if (neighbors0->id == 2) found2 = true;
        neighbors0 = neighbors0->next;
    }
    CHECK(found1);  // Neighbor 1 should be found
    CHECK(found2);  // Neighbor 2 should be found

    bool found3 = false;
    while (neighbors2) {
        if (neighbors2->id == 3) found3 = true;
        neighbors2 = neighbors2->next;
    }
    CHECK(found3);  // Neighbor 3 should be found
}
