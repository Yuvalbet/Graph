#include "Algorithms.hpp"
#include "Graph.hpp"
#include "UnionFind.hpp"
#include "BubbleSort.hpp"
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
        Graph tree(vertices);  // יצירת עץ DFS מכוון

        int* parent = new int[vertices];  // מערך לזיהוי ההורה של כל צומת
        for (int i = 0; i < vertices; i++) {
            parent[i] = -1;  // אתחול - אין הורה לצמתים בהתחלה
        }

        stack.push(startVertex);  // הכנסת הצומת ההתחלתי

        while (!stack.isEmpty()) {
            int current = stack.pop();

            if (!visited[current]) {
                visited[current] = true;

                // אם זה לא הצומת ההתחלתי, נוסיף קשת בגרף החדש
                if (parent[current] != -1) {
                    int parentVertex = parent[current];

                    // מציאת המשקל מהגרף המקורי
                    Node* temp = graph.getNeighbors(parentVertex);
                    while (temp) {
                        if (temp->id == current) {
                            tree.addOneEdge(parentVertex, current, temp->weight); // הוספת קשת מכוונת
                            break;
                        }
                        temp = temp->next;
                    }
                }

                // מעבר על השכנים של הצומת הנוכחי
                Node* temp = graph.getNeighbors(current);
                while (temp) {
                    int neighbor = temp->id;
                    if (!visited[neighbor]) {
                        stack.push(neighbor);
                        parent[neighbor] = current;  // שמירת האב של הצומת
                    }
                    temp = temp->next;
                }
            }
        }

        delete[] visited;
        delete[] parent;
        return tree;  // החזרת עץ DFS מכוון
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

    Graph Algorithms::prim(const Graph& graph) {
    int vertices = graph.getVertices();
    Graph mst(vertices); // יצירת גרף חדש עבור עץ פורש מינימלי

    int* parent = new int[vertices];  // לשמירת אב של כל צומת
    int* key = new int[vertices];     // משקל מינימלי לכל צומת
    bool* inMST = new bool[vertices]{false}; // בדיקה אם צומת ב-MST

    PriorityQueue pq(vertices);

    // אתחול המערכים
    for (int i = 0; i < vertices; i++) {
        key[i] = 999999; // ערך גבוה המדמה אינסוף
        parent[i] = -1;  // אין הורה בתחילה
    }

    // מתחילים מצומת 0 (אפשר להתחיל מכל צומת)
    key[0] = 0;
    pq.push(0, 0);

    while (!pq.isEmpty()) {
        int u = pq.pop(); // הצומת עם המשקל המינימלי

        inMST[u] = true;

        // מעבר על כל השכנים של u
        Node* temp = graph.getNeighbors(u);
        while (temp) {
            int v = temp->id;
            int weight = temp->weight;

            if (!inMST[v] && weight < key[v]) { // אם הצומת לא ב-MST ומשקלו קטן מהמשקל הנוכחי
                key[v] = weight;
                parent[v] = u;
                pq.decreaseKey(v, weight);
                pq.push(v, weight);
            }
            temp = temp->next;
        }
    }

    // הוספת הצלעות לעץ ה-MST
    for (int i = 1; i < vertices; i++) {
        if (parent[i] != -1) {
            mst.addEdge(parent[i], i, key[i]); // גרף לא מכוון
        }
    }

    delete[] parent;
    delete[] key;
    delete[] inMST;

    return mst;
}



    Graph Algorithms::kruskal(Graph& g) {
    int vertices = g.getVertices();
    int edgeCount = 0;

    // 1. קבלת כל הקשתות בגרף והכנסתן למערך
    Edge* edges = g.getAllEdges(edgeCount);  // קבלת כל הקשתות
     int index = edgeCount;

    // 2. מיון הקשתות לפי משקל בעזרת מיון בועות
    BubbleSort::sort(edges, index);  // מיון הקשתות לפי משקל

    // 3. יצירת מבנה Union-Find
    UnionFind uf(vertices);
    Graph mst(vertices);  // הגרף של MST

    int mstWeight = 0;  // משקל ה-MST

    // 4. בחירת הקשתות ל-MST
    for (int i = 0; i < index; ++i) {
        int src = edges[i].src;
        int dest = edges[i].dest;

        // אם הצמתים שייכים לקבוצות שונות, נוסיף את הקשת ל-MST
        if (uf.find(src) != uf.find(dest)) {
            // הוספת הקשת לגרף ה-MST
            mst.addEdge(src, dest, edges[i].weight);
            mstWeight += edges[i].weight;  // הוספת משקל הקשת
            uf.unionSets(src, dest);  // מאחד את הקבוצות
        }
    }

    // הדפסת התוצאה
    std::cout << "Minimum Spanning Tree edges:" << std::endl;
    mst.print_graph();  // הדפסת הגרף של ה-MST
    std::cout << "Total weight of MST: " << mstWeight << std::endl;

    delete[] edges;  // שחרור הזיכרון שהוקצה לקשתות

    return mst;  // החזרת הגרף של ה-MST
}
}

