#include "Algorithms.hpp"
#include <iostream>

namespace graph {
    void Algorithms::bfs(const Graph& graph, int startVerex){
        int vertices = graph.getVertices();
        //מערך לבדיקת ביקור בצמתים
        bool* visited = new bool[vertices]{false};
        //יצירת תור בגודל הגרף
        Queue q(vertices);

        visited[startVerex] == true;
        q.enqueue(startVerex);

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
}