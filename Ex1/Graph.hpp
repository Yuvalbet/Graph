#ifndef GRAPH.HPP
#define GRAPH.HPP

namespace graph {

    struct Node {
        int id;         
        int weight;
        Node* next;
    };
    
    class Graph {
        private:
        int vertices;
        Node** adjList;



        public:
        Graph(int vertices);

        ~Graph();


        void addEdge(int src, int dest, int weight);

        void removeEdge(int src, int dest);

        void print_graph();



    };
}

#endif