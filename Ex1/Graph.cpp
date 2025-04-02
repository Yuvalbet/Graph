/*
Email: yuvali532@gmail.com
*/
#include "Graph.hpp"
#include <iostream>

namespace graph {
    /*
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
    
    */
    Graph::Graph(int vertices) {
        // להוסיף תנאי אם מס הקודקודים שלילי 
        this->vertices = vertices;
        adjList = new Node*[vertices];
        for (int i = 0; i < vertices; i++) {
            adjList[i] = nullptr;
        }
    }
        

    Graph::~Graph() {
        for (int i = 0; i < vertices; i++) {
            Node* current = adjList[i];
            while (current) {
                Node* temp = current;
                current = current->next;
                // Delete every node in the list
                delete temp;  
            }
        }
        // Delete the pointer array
        delete[] adjList;  
    }

    void Graph::addEdge(int src, int dest, int weight) {
        if (src < 0 || dest < 0 || src >= vertices || dest >= vertices) {
            std::cerr << "Error: The vertex not found" << std::endl;
            return;
        }
        // להוסיף תנאי אם צלע כבר קיימת לפני שמוסיפים אותה
        /*
         // בודק אם הצלע כבר קיימת לפני שמוסיפים אותה
        Node* current = adjList[src];
        while (current) {
        if (current->id == dest) {
            std::cerr << "Error: Edge already exists from " << src << " to " << dest << std::endl;
            return;
        }
        current = current->next;
        }
        */
        
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
        // להוסיף תנאי אם צלע כבר קיימת לפני שמוסיפים אותה
        /*
         // בודק אם הצלע כבר קיימת לפני שמוסיפים אותה
        Node* current = adjList[src];
        while (current) {
        if (current->id == dest) {
            std::cerr << "Error: Edge already exists from " << src << " to " << dest << std::endl;
            return;
        }
        current = current->next;
        }
        */
       
        // Create a new edge only in the direction src → dest (directed graph)
        Node* newNode = new Node{dest, weight, adjList[src]};
        adjList[src] = newNode;
    }
    /*
    void Graph::removeEdge(int src, int dest) {
    if (src < 0 || dest < 0 || src >= vertices || dest >= vertices) {
        std::cerr << "Error: The vertex not found" << std::endl;
        return;
    }

    // בדיקה אם הצלע קיימת
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

    // הסרת הקשת מקודקוד src
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

    // הסרת הקשת מקודקוד dest
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

    */
    void Graph::removeEdge(int src, int dest) {
        if (src < 0 || dest < 0 || src >= vertices || dest >= vertices) {
            std::cerr << "Error: The vertex not found" << std::endl;
            return;
        }
        // להוסיף תנאי אם צלע כבר קיימת לפני שמוסיפים אותה

        // Remove edge from src node
        Node* current = adjList[src];
        Node* prev = nullptr;
        while (current && current->id != dest) {
            prev = current;
            current = current->next;
        }

        if (!current) {
            std::cerr << "Error: Edge not found" << std::endl;
            return;
        }

        if (prev)
            prev->next = current->next;
        else
            // Remove from the end of the list
            adjList[src] = current->next; 

        delete current;

        // Two-way removal for the edge at node dest
        current = adjList[dest];
        prev = nullptr;

        while (current && current->id != src) {
            prev = current;
            current = current->next;
        }

        if (!current) return;

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