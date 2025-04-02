/*
Email: yuvali532@gmail.com
*/
#ifndef GRAPH_HPP
#define GRAPH_HPP

namespace graph {

    //Data structure of a node in a list of nodes 
    struct Node {
        int id;         
        int weight;
        Node* next;
    };

    //Data structure of an edge in a graph
    struct Edge {
        int src;
        int dest;
        int weight;
    };

    class Graph {
        private:
        //Number of nodes in the graph
        int vertices;
        //array of adjacency list
        Node** adjList;



        public:
        //Constructor, creates a graph with a choosen number of nodes
        Graph(int vertices);

        //Destractor, frees all dynamic memory allocated to the neighborhood list
        ~Graph();

        
        //Function to add a two-way edge (undirected graph)
        void addEdge(int src, int dest, int weight);

        //Function to add a one-way edge (to a directed graph)
        void addOneEdge(int src, int dest, int weight);

        //Function to remove an edge from the graph (in both directions if the graph is undirected)
        void removeEdge(int src, int dest);

        //Function to print the graph for the neighborhood list
        void print_graph() const;

        //Function that returns the list of neighbors of the node
        Node* getNeighbors(int vertex) const;

        //Another function to get the number of nodes in the graph
        int getVertices() const;

        //Function that returns the list of neighborhoods
        Node** getAdjList() const;

        //Function that returns all edges in the graph as an array of Edge
        Edge* getAllEdges(int& edgeCount) const;

    

    };
}

#endif