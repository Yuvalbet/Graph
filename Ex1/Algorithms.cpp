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

    
    void Algorithms::dijkstra(const Graph& graph, int startVertex){
        int vertices = graph.getVertices();
        int* distances = new int[vertices];
        //מערך לבדיקת ביקור בצמתים
        bool* visited = new bool[vertices]{false};
        //יצירת תור עדיפויות בגודל מספר הצמתים
        PriorityQueue pq(vertices);

        //מכיוון שאסור להשתמש ב<vector> נגדיר מספר גדול INF
        const int INF = 999999;
        //אתחול המרחקים לכל הצמתים
        for(int i = 0; i < vertices; i++){
            distances[i] = INF;
        }
        distances[startVertex] = 0;
        //נכניס את הצומת ההתחלתי
        pq.push(startVertex,0);

        while (!pq.isEmpty()){
            int current = pq.pop();

            if(visited[current])
                continue;

            visited[current] = true;
                 
            //נעבור על כל השכנים של הצומת הנוכחי
            Node* temp = graph.getNeighbors(current);
            while (temp){
                int neighbor = temp->id;
                int weight = temp->weight;

                if (!visited[neighbor] && distances[current] + weight < distances[neighbor]){
                    distances[neighbor] = distances[current] + weight;
                    pq.push(neighbor, distances[neighbor]);
                }
                temp = temp->next;  
            }
        }
        //הדפסת המרחקים מהצומת ההתחלתי
        std::cout << "Dijkstra's shortest paths from vertex" << startVertex << ":\n";
        for (int  i = 0; i < vertices; i++){
            if (distances[i] == INF)
                std::cout << "To " << i << ": No path" << std::endl;
            else
                std::cout << "To " << i << ": " << distances[i] << std::endl;
        }
        
        delete[] distances;
        delete[] visited;
        
    }

}