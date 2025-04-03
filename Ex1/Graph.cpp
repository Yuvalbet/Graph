/*
Email: yuvali532@gmail.com
*/
#include "Graph.hpp"
#include <iostream>

namespace graph {
    
    Graph::Graph(int vertices) {
        if (vertices < 0) {
            std::cerr << "Error: Number of vertices cannot be negative." << std::endl;
            this->vertices = 0;  // You can choose to set it to 0 or handle it differently
            adjList = nullptr;  // Ensure no memory is allocated if invalid
            return;
        }
        this->vertices = vertices;
        adjList = new Node*[vertices];
        for (int i = 0; i < vertices; i++) {
            adjList[i] = nullptr;
        }
    }
    

    Graph::~Graph() {
        // Ensure we only free allocated memory
        if (adjList) {  
            for (int i = 0; i < vertices; i++) {
                Node* current = adjList[i];
                while (current) {
                    Node* temp = current;
                    current = current->next;
                    // Free each node in the adjacency list
                    delete temp;  
                }
            }
            // Free the adjacency list itself
            delete[] adjList; 
            // Avoid dangling pointers
            adjList = nullptr;  // Avoid dangling pointers
        }
    }
    
        

    void Graph::addEdge(int src, int dest, int weight) {
        if (src < 0 || dest < 0 || src >= vertices || dest >= vertices) {
            std::cerr << "Error: The vertex not found" << std::endl;
            return;
        }
        
        // Checks if the edge already exists before adding it
        Node* current = adjList[src];
        while (current) {
            if (current->id == dest) {
                std::cerr << "Error: Edge already exists from " << src << " to " << dest << std::endl;
                return;
            }
            current = current->next;
        }
        
        
        // Create a new edge at the src node
        Node* newNode = new Node{dest, weight, adjList[src]};  
        adjList[src] = newNode;

        // Create another edge at node dest if the graph is undirected
        newNode = new Node{src, weight, adjList[dest]};  
        adjList[dest] = newNode;
    }

    void Graph::addOneEdge(int src, int dest, int weight) {
        if (src < 0 || dest < 0 || src >= vertices || dest >= vertices) {
            std::cerr << "Error: The vertex not found" << std::endl;
            return;
        }
       
        // Checks if the edge already exists before adding it
        Node* current = adjList[src];
        while (current) {
            if (current->id == dest) {
                std::cerr << "Error: Edge already exists from " << src << " to " << dest << std::endl;
                return;
            }
            current = current->next;
        }
       
        // Create a new edge only in the direction src → dest (directed graph)
        Node* newNode = new Node{dest, weight, adjList[src]};
        adjList[src] = newNode;
    }
    
    void Graph::removeEdge(int src, int dest) {
        if (src < 0 || dest < 0 || src >= vertices || dest >= vertices) {
            std::cerr << "Error: The vertex not found" << std::endl;
            return;
        }

        // Check if the edge exists
        bool edgeExists = false;
        Node* current = adjList[src];
        while (current) {
            if (current->id == dest) {
                edgeExists = true;
                break;
            }
            current = current->next;
        }

        if (!edgeExists) {
            std::cerr << "Error: Edge does not exist between " << src << " and " << dest << std::endl;
            return;
        }

        // Remove the edge from the src vertex
        current = adjList[src];
        Node* prev = nullptr;
        while (current && current->id != dest) {
            prev = current;
            current = current->next;
        }

        if (prev)
            prev->next = current->next;
        else
            adjList[src] = current->next; 

        delete current;

        // Remove the edge from vertex dest
        current = adjList[dest];
        prev = nullptr;

        while (current && current->id != src) {
            prev = current;
            current = current->next;
        }

        if (prev)
            prev->next = current->next;
        else
            adjList[dest] = current->next;

        delete current;
    }


    void Graph::print_graph() const {
        if(vertices > 0){
            for (int i = 0; i < vertices; i++) {
                std::cout << "Vertex " << i << ": ";
                Node* current = adjList[i];
        
                if(!current){
                    std::cout << "No children";
                }else{
                    while (current) {
                        // If the vertex is not connected to any node
                        std::cout << "(" << current->id << ", " << current->weight << ") ";  
                        current = current->next;
                    }
                }
                std::cout << std::endl;
            }
        }
        else{
            std::cout << "empty Graph" << std::endl;
        }
        
    }


    Node* Graph:: getNeighbors(int vertex) const{
        if (vertex < 0 || vertex >= vertices){
            return nullptr;
        }
        return adjList[vertex];
    }

    int Graph::getVertices() const{
        return vertices;
    }

    Node** Graph::getAdjList() const{
        return adjList;
    }


    Edge* Graph::getAllEdges(int& edgeCount) const{
        edgeCount = 0;
        // Count the number of edges
        Node** adjList = getAdjList();
        for (int i = 0; i < vertices; i++) {
            Node* current = adjList[i];
            while (current) {
                edgeCount++;
                current = current->next;
            }
        }

        // Represent all the edges in an Edge array
        Edge* edges = new Edge[edgeCount];
        int index = 0;
        for (int i = 0; i < vertices; i++) {
            Node* current = adjList[i];
            while (current) {
                edges[index].src = i;
                edges[index].dest = current->id;
                edges[index].weight = current->weight;
                index++;
                current = current->next;
            }
        }
        return edges;
    }
}