/*
Email: yuvali532@gmail.com
*/
#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include "PriorityQueue.hpp"

namespace graph {


    class Algorithms{ 

        private:
        
        static void relax(int u, int v, int weight, int* distances, int* parents, PriorityQueue& pq, bool* visited);


        public:
            static Graph bfs(const Graph& graph, int startVertex);

            static Graph dfs(const Graph& graph, int startVertex);

            static Graph* dijkstra(const Graph& graph, int startVertex);

            static Graph prim(const Graph& graph);

            static Graph kruskal(Graph& g);
    };
    
}



#endif