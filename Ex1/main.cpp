/*
Email: yuvali532@gmail.com
*/
#include <iostream>
#include "Graph.hpp"
#include "Algorithms.hpp"

using namespace graph;

int main(){
    // על גרף עם אפס קודקודים ולהוסיף הערות על גרף עם שלילי להוסיף הערות 
    Graph g7(0); 
    g7.print_graph();

    // על גרף עם אפס קודקודים ולהוסיף הערות על גרף עם שלילי להוסיף הערות 
    Graph g8(-3); 
    g8.print_graph();

    Graph g(6);
    

    g.addEdge(0,1,4);
    //להוסיף את הערה על הבדיקה של צלע שכבר נמצאת
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

    std::cout << "\nafter Dijkstra;\n";

    //מחזיר פוינטר לגרף עם אפס קודקודים- זה גרם לי לבעיות ובגלל זה החזרתי פוינטר
    Graph* g4 = Algorithms::dijkstra(g,0);
    if(g4 == nullptr){
        std::cerr << "A problem has occured in the tree" << std::endl;
    }
    else{
        g4->print_graph();
        delete g4; 
    }
    

    std::cout << "\nafter Prim;\n";

    Graph g5 = Algorithms::prim(g);
    g5.print_graph();

    std::cout << "\nafter Kruskal;\n";

    Graph g6 = Algorithms::kruskal(g);
    g6.print_graph();

    



//לכתוב הערה על צלע שלא נמאצת
    g.removeEdge(4,5);
    g.removeEdge(4,5);

    
    return 0;


}