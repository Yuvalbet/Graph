#ifndef ALGORITHMS.HPP
#define ALGORITHMS.HPP

#include "Graph.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include "PriorityQueue.hpp"

namespace graph {
    class Algorithms{ 
        private:


        public:
            static void bfs(const Graph& graph, int startVertex);
            static void dfs(const Graph& graph, int startVertex);
            static void dijkstra(const Graph& graph, int startVertex);
    };
}



#endif