#include "Algorithms.hpp"
#include <iostream>

namespace graph {
    void Algorithms::bfs(const Graph& graph, int startVertex){
        int vertices = graph.getVertices();
        //מערך לבדיקת ביקור בצמתים
        bool* visited = new bool[vertices]{false};
        //יצירת תור בגודל הגרף
        Queue q(vertices);

        visited[startVertex] == true;
        q.enqueue(startVertex);

        while (!q.isEmpty()){
            int current = q.dequeue();
            std::cout << current << " ";
        
            //נעבור על כל השכנים של הצומת הנוכחי
            Node* temp = graph.getAdjList()[current];
            while (temp){
                if (!visited[temp->id]){
                    visited[temp->id] = true;
                    q.enqueue(temp->id);
                }
                temp = temp->next;  
            }
        }
        std::cout << std::endl;
        delete[] visited;
        
    }


    void Algorithms::dfs(const Graph& graph, int startVertex){
        int vertices = graph.getVertices();
        //מערך לבדיקת ביקור בצמתים
        bool* visited = new bool[vertices]{false};
        //יצירת מחסנית בגודל מספר הצמתים
        Stack stack(vertices);

        //נכניס את הצומת ההתחלתי למחסנית
        stack.push(startVertex);

        while (!stack.isEmpty()){
            int current = stack.pop();

            if (!visited[current]){
                std::cout << current << " ";
                visited[current] = true;
            }
                 
            //נעבור על כל השכנים של הצומת הנוכחי
            Node* temp = graph.getAdjList()[current];
            while (temp){
                if (!visited[temp->id]){
                    //נדחוף למחסנית רק צמתים שלא ביקרנו בהם
                    stack.push(temp->id);
                }
                temp = temp->next;  
            }
        }
        std::cout << std::endl;
        delete[] visited;
        
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
            Node* temp = graph.getAdjList()[current];
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