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
            static Graph* dijkstra(const Graph& graph, int startVertex);
            static Graph prim(const Graph& graph);
            static Graph kruskal(Graph& g);
    };
    
}



#endif