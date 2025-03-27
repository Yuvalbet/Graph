#include "Graph.hpp"
#include <iostream>

namespace graph {
    Graph::Graph(int vertices) {
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
                delete temp;  // מחיקת כל צומת ברשימה
            }
        }
        delete[] adjList;  // מחיקת מערך המצביעים
    }

    void Graph::addEdge(int src, int dest, int weight) {
        if (src < 0 || dest < 0 || src >= vertices || dest >= vertices) {
            std::cerr << "Error: The vertex not found" << std::endl;
            return;
        }

        // יצירת קשת חדשה בצומת src
        Node* newNode = new Node{dest, weight, adjList[src]};  
        adjList[src] = newNode;

        // יצירת קשת נוספת בצומת dest אם הגרף הוא לא מכוון
        newNode = new Node{src, weight, adjList[dest]};  
        adjList[dest] = newNode;
    }

    void Graph::addOneEdge(int src, int dest, int weight) {
        if (src < 0 || dest < 0 || src >= vertices || dest >= vertices) {
            std::cerr << "Error: The vertex not found" << std::endl;
            return;
        }
    
        // יצירת קשת חדשה רק בכיוון src → dest (לגרף מכוון)
        Node* newNode = new Node{dest, weight, adjList[src]};
        adjList[src] = newNode;
    }

    void Graph::removeEdge(int src, int dest) {
        if (src < 0 || dest < 0 || src >= vertices || dest >= vertices) {
            std::cerr << "Error: The vertex not found" << std::endl;
            return;
        }

        // הסרת קשת מצומת src
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
            adjList[src] = current->next;  // הסרה מקצה הרשימה

        delete current;

        // הסרה דו-כיוונית עבור הקשת בצומת dest
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
        for (int i = 0; i < vertices; i++) {
            std::cout << "Vertex " << i << ": ";
            Node* current = adjList[i];
    
            if(!current){
                std::cout << "No children";
            }else{
                while (current) {
                    std::cout << "(" << current->id << ", " << current->weight << ") ";  // אם הקודקוד לא מחובר לאף צומת
                    current = current->next;
                }
            }
            std::cout << std::endl;
        }
    }


    Node* Graph:: getNeighbors(int vertex) const{
        if (vertex < 0 || vertex >= vertices){
            return nullptr;
        }
        return adjList[vertex];
    }

    int Graph::getVertexCount() const{
        return vertices;
    }

    int Graph::getVertices() const{
        return vertices;
    }

    Node** Graph::getAdjList() const{
        return adjList;
    }
}

