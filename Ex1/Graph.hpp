#ifndef GRAPH.HPP
#define GRAPH.HPP

namespace graph {

    
    class Graph {
        private:



        public:
        Graph(int vertices);

        ~Graph();


        void addEdge(int src, int dest, int weight);

        void removeEdge(int src, int dest);

        void print_graph();



    };
}

#endif