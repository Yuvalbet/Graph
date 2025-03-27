#ifndef ALGORITHMS.HPP
#define ALGORITHMS.HPP

#include "Graph.hpp"
#include "Queue.hpp"

namespace graph {
    class Algorithms{ 
        private:


        public:
            static void bfs(const Graph& graph, int startVertex);
    };
}



#endif