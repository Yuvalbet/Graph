#include "Algorithms.hpp"
#include "Graph.hpp"
#include "UnionFind.hpp"
#include "BubbleSort.hpp"
#include <iostream>

namespace graph {
    Graph Algorithms::bfs(const Graph& graph, int startVertex) {
        int vertices = graph.getVertices();
        //מערך לבדיקה אילו צמתים כבר בוקרו
        bool* visited = new bool[vertices] {false};
        // יצירת גרף חדש שיכיל את עץ הbfs
        Graph tree(vertices); 

        //יצירת תור לעיבוד הצמתים
        Queue q(vertices);
        //סימון הצומת ההתחלתי כבוצע
        visited[startVertex] = true;
        //הכנסה לתור של הצומת ההתחלתי
        q.enqueue(startVertex);

        
        while (!q.isEmpty()) {
            //שליפת הצומת הראשון מהתור
            int current = q.dequeue();
            

            // מעבר על השכנים של הצומת הנוכחי
            Node* temp = graph.getAdjList()[current];

            //מעבר על כל השכנים של הצומת הנוכחי
            while (temp) {
                int neighbor = temp->id;
                int weight = temp->weight; // שומרים את המשקל המקורי

                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.enqueue(neighbor);

                    // הוספת הקשת בין הצומת הנוכחי לשכן שלו לעץ הbfs
                    tree.addOneEdge(current, neighbor, weight);
                }
                //מעבר לשכן הבא
                temp = temp->next;
            }
        }
        //שחרור זכרון
        delete[] visited;
        return tree;
    }


    Graph Algorithms::dfs(const Graph& graph, int startVertex) {
        int vertices = graph.getVertices();
        //יצירת מערך ביקור לכל הצמתים, מאותחל בfalse
        bool* visited = new bool[vertices]{false};
        //מחסנית לניהול סדר הביקור בצמתים
        Stack stack(vertices);
        Graph tree(vertices);

        // מערך לזיהוי ההורה של כל צומת
        int* parent = new int[vertices]; 
        for (int i = 0; i < vertices; i++) {
             // אתחול - אין הורה לצמתים בהתחלה
            parent[i] = -1; 
        }

        // הכנסת הצומת ההתחלתי
        stack.push(startVertex); 

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
                         //עדכון ההורה של הצומת השכן
                        parent[neighbor] = current; 
                    }
                    temp = temp->next;
                }
            }
        }

        delete[] visited;
        delete[] parent;
        return tree;  // החזרת עץ DFS מכוון
    }

Graph* Algorithms::dijkstra(const Graph& graph, int startVertex) {
    int vertices = graph.getVertices();
    if(startVertex < 0 || startVertex >= vertices){
            std::cout << "Error: Start vertex is out of range. \n" << std::endl;
            return nullptr;
        }
        //בדיקה אם קיימת קשת עם משקל שלילי
        for(int i = 0; i < vertices; i++){
            Node* temp = graph.getNeighbors(i);
            while (temp){
                bool ans = temp->weight < 0;
               if(temp->weight < 0){
                std::cout << "Error: Dijkstra cannot  handle negative edge weight." << std::endl;
                return nullptr;
               }
               temp = temp -> next;
            }
        }
            
    //מערך מרחקים
    int* distances = new int[vertices];
    //מערך ביקורים
    bool* visited = new bool[vertices]{false};
    //מערך הורים לצורך שחזור המסלול
    int* parents = new int[vertices]; 

//תור עדיפויות לניהול הצמתים לבדיקה
PriorityQueue pq(vertices);
const int INF = 999999;
 // עץ דייקסטרה המוחזר
 Graph* dijkstraTree = new Graph(vertices);

for (int i = 0; i < vertices; i++) {
    distances[i] = INF;
     // ערך התחלתי שמציין שאין הורה
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

        if (!visited[neighbor] && distances[current] + weight < distances[neighbor]) {
            distances[neighbor] = distances[current] + weight;
             // שמירת האב של הקודקוד
            parents[neighbor] = current;
            pq.push(neighbor, distances[neighbor]);
        }
        temp = temp->next;
    }
}

// בניית עץ דייקסטרה מהתוצאות
for (int i = 0; i < vertices; i++) {
    if (parents[i] != -1) { 
        // הוספת קשת לעץ רק אם לקודקוד יש הורה (כלומר, נמצא במסלול)
        dijkstraTree->addOneEdge(parents[i], i, distances[i] - distances[parents[i]]);
    }
}

delete[] distances;
delete[] visited;
delete[] parents;

return dijkstraTree;
}

Graph Algorithms::prim(const Graph& graph) {
    int vertices = graph.getVertices();
    // יצירת גרף חדש עבור עץ פורש מינימלי
    Graph mst(vertices);

    // לשמירת אב של כל צומת
    int* parent = new int[vertices]; 
    // משקל מינימלי לכל צומת
    int* key = new int[vertices];    
    // בדיקה אם צומת ב-MST
    bool* inMST = new bool[vertices]{false};

    PriorityQueue pq(vertices);

    // אתחול המערכים
    for (int i = 0; i < vertices; i++) {
        // ערך גבוה המדמה אינסוף
        key[i] = 999999;
        // אין הורה בתחילה
        parent[i] = -1;
    }

    // מתחילים מצומת 0 (אפשר להתחיל מכל צומת)
    key[0] = 0;
    pq.push(0, 0);

    while (!pq.isEmpty()) {
        // הצומת עם המשקל המינימלי
        int u = pq.pop();

        inMST[u] = true;

        // מעבר על כל השכנים של u
        Node* temp = graph.getNeighbors(u);
        while (temp) {
            int v = temp->id;
            int weight = temp->weight;

            // אם הצומת לא ב-MST ומשקלו קטן מהמשקל הנוכחי
            if (!inMST[v] && weight < key[v]) {
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
            // גרף לא מכוון
            mst.addEdge(parent[i], i, key[i]);
        }
    }

    delete[] parent;
    delete[] key;
    delete[] inMST;

    return mst;
}



    Graph Algorithms::kruskal(Graph& g) {
    //מספר הצמתים בגרף
    int vertices = g.getVertices();
    int edgeCount = 0;

    // קבלת כל הקשתות בגרף והכנסתן למערך
    Edge* edges = g.getAllEdges(edgeCount); 
     int index = edgeCount;

    // מיון הקשתות לפי משקל בעזרת מיון בועות
    BubbleSort::sort(edges, index); 

    // יצירת מבנה Union-Find
    UnionFind uf(vertices);
    // הגרף של MST
    Graph mst(vertices);

     // משתנה לשמירת משקל הmst
    int mstWeight = 0; 

    // בחירת הקשתות ל-MST
    for (int i = 0; i < index; ++i) {
        int src = edges[i].src;
        int dest = edges[i].dest;

        // אם הצמתים שייכים לקבוצות שונות, נוסיף את הקשת ל-MST
        if (uf.find(src) != uf.find(dest)) {
            // הוספת הקשת לגרף ה-MST
            mst.addEdge(src, dest, edges[i].weight);
            // הוספת משקל הקשת
            mstWeight += edges[i].weight; 
            // מאחד את קבוצות הצמתים
            uf.unionSets(src, dest);
        }
    }
    // שחרור הזיכרון שהוקצה לקשתות
    delete[] edges; 
    // החזרת הגרף של ה-MST
    return mst;
}
}

