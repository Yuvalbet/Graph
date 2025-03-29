#ifndef GRAPH_HPP
#define GRAPH_HPP

namespace graph {

    struct Node {
        int id;         
        int weight;
        Node* next;
    };

    struct Edge {
        int src;
        int dest;
        int weight;
    };

    class Graph {
        private:
        int vertices;
        Node** adjList;



        public:
        Graph(int vertices);
        ~Graph();


        void addEdge(int src, int dest, int weight);
        void addOneEdge(int src, int dest, int weight);
        void removeEdge(int src, int dest);
        void print_graph() const;
        
        //פונקציה שמחזירה את רשימת השכנית של הצומת
        Node* getNeighbors(int vertex) const;
        //פונקציה שמחזירה את מספר הצמתים שבגרף
        int getVertexCount() const;

        int getVertices() const;
        Node** getAdjList() const;

        Edge* getAllEdges(int& edgeCount);
    

    };
}

#endif