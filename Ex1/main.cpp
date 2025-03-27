#include <iostream>
#include "Graph.hpp"
#include "Algorithms.hpp"

using namespace graph;

int main(){

    Graph g(6);


    g.addEdge(0,1,4);
    g.addEdge(0,2,3);
    g.addEdge(1,2,1);
    g.addEdge(1,3,2);
    g.addEdge(2,3,4);
    g.addEdge(3,4,2);
    g.addEdge(4,5,6);

    
    g.print_graph();

   
    std::cout << "\nafter BFS;\n";

    Graph g2 = Algorithms::bfs(g,0);
    g2.print_graph();

    std::cout << "\nafter DFS;\n";
    Graph g3 = Algorithms::dfs(g,0);
    g3.print_graph();



    

    return 0;


}