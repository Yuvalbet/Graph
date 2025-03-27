#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include "PriorityQueue.hpp"

namespace graph {
    class Algorithms{ 
        private:


        public:
            static Graph bfs(const Graph& graph, int startVertex);
            static Graph dfs(const Graph& graph, int startVertex);
            static void dijkstra(const Graph& graph, int startVertex);
    };
}



#endif