/*
Email: yuvali532@gmail.com
*/
#include "Algorithms.hpp"
#include "Graph.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include "PriorityQueue.hpp"
#include "UnionFind.hpp"
#include "BubbleSort.hpp"
#include <iostream>


namespace graph {
    
    Graph Algorithms::bfs(const Graph& graph, int startVertex) {
        int vertices = graph.getVertices();
        //Array to check which nodes have already been checked
        bool* visited = new bool[vertices] {false};
        // Create a new graph that will contain the bfs tree
        Graph tree(vertices); 
        //Create a queue for processing nodes
        Queue q(vertices);
        //Mark the starting node as done
        visited[startVertex] = true;
        q.enqueue(startVertex);

        
        while (!q.isEmpty()) {
            //Retrieve the first node from the queue
            int current = q.dequeue();
            

            // Traverse the neighbors of the current node
            Node* temp = graph.getAdjList()[current];

            // Traverse all neighbors of the current node
            while (temp) {
                int neighbor = temp->id;
                int weight = temp->weight; 

                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.enqueue(neighbor);

                    // Add the edge between the current node and its neighbor to the bfs tree
                    tree.addOneEdge(current, neighbor, weight);
                }
                temp = temp->next;
            }
        }
        //Release memory
        delete[] visited;
        return tree;
    }


    Graph Algorithms::dfs(const Graph& graph, int startVertex) {
        int vertices = graph.getVertices();
        //Create a visit array for all nodes, initialized to false
        bool* visited = new bool[vertices]{false};
        //Stack for managing the order of visiting nodes
        Stack stack(vertices);
        Graph tree(vertices);

        // Array to identify the parent of each node
        int* parent = new int[vertices]; 
        for (int i = 0; i < vertices; i++) {
            // Initialization - no parent for nodes at first
            parent[i] = -1; 
        }

        // Insert the starting node
        stack.push(startVertex); 

        while (!stack.isEmpty()) {
            int current = stack.pop();

            if (!visited[current]) {
                visited[current] = true;

                // If this is not the starting node, we will add an edge in the new graph
                if (parent[current] != -1) {
                    int parentVertex = parent[current];

                    // Finding the weight from the original graph
                    Node* temp = graph.getNeighbors(parentVertex);
                    while (temp) {
                        if (temp->id == current) {
                            // Add a directed edge
                            tree.addOneEdge(parentVertex, current, temp->weight); 
                            break;
                        }
                        temp = temp->next;
                    }
                }

                // Traverse the neighbors of the current node
                Node* temp = graph.getNeighbors(current);
                while (temp) {
                    int neighbor = temp->id;
                    if (!visited[neighbor]) {
                        stack.push(neighbor);
                        //Update the parent of the neighboring node
                        parent[neighbor] = current; 
                    }
                    temp = temp->next;
                }
            }
        }

        delete[] visited;
        delete[] parent;
        return tree; 
    }

    Graph* Algorithms::dijkstra(const Graph& graph, int startVertex) {
        int vertices = graph.getVertices();
        if(startVertex < 0 || startVertex >= vertices){
                std::cout << "Error: Start vertex is out of range. \n" << std::endl;
                return nullptr;
        }
        //Check if there is an edge with negative weight
        for(int i = 0; i < vertices; i++){
            Node* temp = graph.getNeighbors(i);

            while (temp){

                if(temp->weight < 0){
                    std::cout << "Error: Dijkstra cannot  handle negative edge weight." << std::endl;
                    return nullptr;
                }
                temp = temp -> next;
            }
        }
                
        //Distance array
        int* distances = new int[vertices];
        //Visit array
        bool* visited = new bool[vertices]{false};
        //Parent array for route reconstruction
        int* parents = new int[vertices]; 

        //Priority queue for managing nodes for testing
        PriorityQueue pq(vertices);
        const int INF = 999999;
        // The returned Dijkstra tree
        Graph* dijkstraTree = new Graph(vertices);

        for (int i = 0; i < vertices; i++) {
            distances[i] = INF;
            // Initial value indicating there is no parent
            parents[i] = -1;
        }

        distances[startVertex] = 0;
        pq.push(startVertex, 0);

        while (!pq.isEmpty()) {
            int current = pq.pop();

            if (visited[current]) continue;
                visited[current] = true;
            
            Node* temp = graph.getNeighbors(current);

            while (temp) {
                    int neighbor = temp->id;
                    int weight = temp->weight;
        
                    relax(current, neighbor, weight, distances, parents, pq, visited);
                    
                    temp = temp->next;
            }
        }
        

        // Build a Dijkstra tree from the results
        for (int i = 0; i < vertices; i++) {
            if (parents[i] != -1) { 
                // Add an edge to the tree only if the vertex has a parent)
                dijkstraTree->addOneEdge(parents[i], i, distances[i] - distances[parents[i]]);
            }
        }

        delete[] distances;
        delete[] visited;
        delete[] parents;

        return dijkstraTree;
    }
    // Check if the vertex v has not been visited yet and if the new computed distance is smaller than the current on
    void Algorithms::relax(int u, int v, int weight, int* distances, int* parents, PriorityQueue& pq, bool* visited) {
        if (!visited[v] && distances[u] + weight < distances[v]) {
            // Update the shortest known distance to vertex v
            distances[v] = distances[u] + weight;
            // Update the parent of vertex v to be u, indicating the shortest path passes through u
            parents[v] = u;
            // Push the updated vertex v into the priority queue with the new distance
            pq.push(v, distances[v]);
        }
    }


    Graph Algorithms::prim(const Graph& graph) {
        int vertices = graph.getVertices();
        // Create a new graph for a minimum spanning tree
        Graph mst(vertices);

        // To save the parent of each node
        int* parent = new int[vertices]; 
        // Minimum weight for each node
        int* key = new int[vertices];    
        // Check if node is in MST
        bool* inMST = new bool[vertices]{false};

        PriorityQueue pq(vertices);

        // Initialize the arrays
        for (int i = 0; i < vertices; i++) {
            // High value simulating infinity
            key[i] = 999999;
            // No parent initially
            parent[i] = -1;
        }

        // Start at node 0
        key[0] = 0;
        pq.push(0, 0);

        while (!pq.isEmpty()) {
            // The node with the minimum weight
            int u = pq.pop();

            inMST[u] = true;

            // Traverse all neighbors of u
            Node* temp = graph.getNeighbors(u);
            while (temp) {
                int v = temp->id;
                int weight = temp->weight;

                // If the node is not in MST and its weight is less than the current weight
                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    parent[v] = u;
                    pq.push(v, weight);
                }
                temp = temp->next;
            }
        }

        // Adding edges to the MST tree
        for (int i = 1; i < vertices; i++) {
            if (parent[i] != -1) {
                // Undirected graph
                mst.addEdge(parent[i], i, key[i]);
            }
        }

        delete[] parent;
        delete[] key;
        delete[] inMST;

        return mst;
    }



    Graph Algorithms::kruskal(Graph& g) {
        //Number of nodes in the graph
        int vertices = g.getVertices();
        int edgeCount = 0;

        // Get all the edges in the graph and put them into an array
        Edge* edges = g.getAllEdges(edgeCount); 
        int index = edgeCount;

        // Sort the edges by weight using bubble sort
        BubbleSort::sort(edges, index); 

        // Create a Union-Find structure
        UnionFind uf(vertices);
        Graph mst(vertices);

        // Variable to store the weight of the mst
        int mstWeight = 0; 

        // Selecting the edges for MST
        for (int i = 0; i < index; ++i) {
            int src = edges[i].src;
            int dest = edges[i].dest;

            // If the nodes belong to different groups, we add the edge to the MST
            if (uf.find(src) != uf.find(dest)) {
                // Adding the edge to the MST graph
                mst.addEdge(src, dest, edges[i].weight);
                // Adding the bow weight
                mstWeight += edges[i].weight; 
                uf.unionSets(src, dest);
            }
        }

        // Freeing the memory allocated to the edges
        delete[] edges; 
        return mst;
    }
}

