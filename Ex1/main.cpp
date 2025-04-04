/*
Email: yuvali532@gmail.com
*/
#include <iostream>
#include "Graph.hpp"
#include "Algorithms.hpp"

using namespace graph;

int main() {

    // Graph with 0 vertices
    std::cout << "Graph with 0 vertices: \n";
    Graph g1(0); 
    g1.print_graph();

    // Graph with negative vertices (invalid case)
    std::cout << "\nGraph with negative vertices: \n";
    Graph g2(-3); 
    g2.print_graph();

    // Creating a graph with 6 vertices and adding edges
    std::cout << "\nCreating Base Graph g3: \n";
    Graph g3(6);
    g3.addEdge(0, 1, 4);
    g3.addEdge(0, 2, 3);
    g3.addEdge(1, 2, 1);
    g3.addEdge(1, 3, 2);
    g3.addEdge(2, 3, 4);
    g3.addEdge(3, 4, 2);
    g3.addEdge(4, 5, 6);
    g3.print_graph();

    // BFS traversal from vertex 0
    std::cout << "\nBFS on g3 from vertex 0: \n";
    Graph g4 = Algorithms::bfs(g3, 0);
    g4.print_graph();

    // DFS traversal from vertex 0
    std::cout << "\nDFS on g3 from vertex 0: \n";
    Graph g5 = Algorithms::dfs(g3, 0);
    g5.print_graph();

    // Dijkstra algorithm from vertex 0
    std::cout << "\nDijkstra on g3 from vertex 0: \n";
    Graph* g6 = Algorithms::dijkstra(g3, 0);
    if (g6 == nullptr) {
        std::cerr << "A problem has occurred in Dijkstra\n";
    } else {
        g6->print_graph();
        delete g6;
    }

    // Prim's algorithm (MST)
    std::cout << "\nPrim on g3: \n";
    Graph g7 = Algorithms::prim(g3);
    g7.print_graph();

    // Kruskal's algorithm (MST)
    std::cout << "\nKruskal on g3: \n";
    Graph g8 = Algorithms::kruskal(g3);
    g8.print_graph();

    // Removing edge 4-5
    std::cout << "\nRemove Edge on g3 \n";

    std::cout << "Graph before removing edge 4-5:\n";
    g3.print_graph();

    std::cout << "\nRemoving edge 4-5\n";
    g3.removeEdge(4, 5);

    // Trying to remove the same edge again (should fail)
    std::cout << "\nAttempting to remove edge 4-5 again (should fail):\n";
    g3.removeEdge(4, 5);

    std::cout << "\nGraph after removal:\n";
    g3.print_graph();

    // Adding duplicate edge 0-1 (should fail)
    std::cout << "\nAttempt to Add Duplicate Edge on g3: \n";

    std::cout << "Adding edge 0-1 again (should fail):\n";
    g3.addEdge(0, 1, 4);

    // Trying to add an invalid edge (vertex out of range)
    std::cout << "\nInvalid Edge Addition on g3: \n";

    std::cout << "Trying to add edge with invalid vertex (0, 6):\n";
    g3.addEdge(0, 6, 1);

    return 0;
}
