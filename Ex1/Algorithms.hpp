#ifndef ALGORITHMS.HPP
#define ALGORITHMS.HPP

#include "Graph.hpp"

namespace graph {
    class Algorithms{ 
        private:


        public:
        Graph BFS(Graph g, int vertix);
        
        Graph DFS(Graph g, int vertix);

        Graph dijkstra(Graph g, int vertix);


    };
}



#endif