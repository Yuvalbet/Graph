#include "Algorithms.hpp"
#include <iostream>

namespace graph {
    Graph Algorithms::bfs(const Graph& graph, int startVertex) {
        int vertices = graph.getVertices();
        bool* visited = new bool[vertices] {false};
        Graph tree(vertices); // יצירת עץ BFS ריק

        Queue q(vertices);
        visited[startVertex] = true;
        q.enqueue(startVertex);

        
        while (!q.isEmpty()) {
            int current = q.dequeue();
            

            // מעבר על השכנים של הצומת הנוכחי
            Node* temp = graph.getAdjList()[current];

            while (temp) {
                int neighbor = temp->id;
                int weight = temp->weight; // שומרים את המשקל המקורי

                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.enqueue(neighbor);

                    // הוספת הקשת לעץ ה-BFS עם המשקל המקורי
                    tree.addOneEdge(current, neighbor, weight);
                }
                temp = temp->next;
            }
        }
        std::cout << std::endl;

        delete[] visited;
        return tree;
    }



    Graph Algorithms::dfs(const Graph& graph, int startVertex) {
        int vertices = graph.getVertices();
        bool* visited = new bool[vertices]{false};  // מערך ביקור
        Stack stack(vertices);  // מחסנית עבור DFS
        Graph tree(vertices);  // יצירת גרף חדש עבור עץ DFS
    
        stack.push(startVertex);  // הכנסת הצומת ההתחלתי
    
        while (!stack.isEmpty()) {
            int current = stack.pop();
    
            if (!visited[current]) {
                visited[current] = true;
            }
    
            Node* temp = graph.getAdjList()[current];  // קבלת רשימת שכנים
    
            while (temp) {
                int neighbor = temp->id;
                int weight = temp->weight;  // שמירת המשקל המקורי (למרות שהוא לא חשוב ל-DFS)
    
                if (!visited[neighbor]) {
                    stack.push(neighbor);
                    tree.addOneEdge(current, neighbor, weight);  // הוספת הצלע לעץ DFS
                }
    
                temp = temp->next;
            }
        }
    
        delete[] visited;
        return tree;  // החזרת עץ DFS
    }


    Graph Algorithms::dijkstra(const Graph& graph, int startVertex) {
        int vertices = graph.getVertices();
        int* distances = new int[vertices];
        bool* visited = new bool[vertices]{false};
        int* parents = new int[vertices]; // שמירת ההורה של כל קודקוד בעץ

    PriorityQueue pq(vertices);
    
    const int INF = 999999;
    Graph dijkstraTree(vertices); // עץ דייקסטרה המוחזר

    for (int i = 0; i < vertices; i++) {
        distances[i] = INF;
        parents[i] = -1; // ערך התחלתי שמציין שאין הורה
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

            if (!visited[neighbor] && distances[current] + weight < distances[neighbor]) {
                distances[neighbor] = distances[current] + weight;
                parents[neighbor] = current; // שמירת האב של הקודקוד
                pq.push(neighbor, distances[neighbor]);
            }
            temp = temp->next;
        }
    }

    // בניית עץ דייקסטרה מהתוצאות
    for (int i = 0; i < vertices; i++) {
        if (parents[i] != -1) { 
            // הוספת קשת לעץ רק אם לקודקוד יש הורה (כלומר, נמצא במסלול)
            dijkstraTree.addOneEdge(parents[i], i, distances[i] - distances[parents[i]]);
        }
    }

    delete[] distances;
    delete[] visited;
    delete[] parents;

    return dijkstraTree;
}
}