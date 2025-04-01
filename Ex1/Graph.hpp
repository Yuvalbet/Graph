#ifndef GRAPH_HPP
#define GRAPH_HPP

namespace graph {

    //מבנה נתונים של צומת ברשימת שכינויות
    struct Node {
        int id;         
        int weight;
        Node* next;
    };

    //מבנה נתונים של צלע בגרף
    struct Edge {
        int src;
        int dest;
        int weight;
    };

    class Graph {
        private:
        //מספר הצמתים בגרף
        int vertices;
        //מערך של רשימת שכינויות
        Node** adjList;



        public:
        //בנאי, יוצר גרף עם מספר צמתים מסויים
        Graph(int vertices);
        //הורס, משחרר את כל הזכרון הדינמי שהוקצה לרשימת השכינויות
        ~Graph();

        //פונקציה להוספת צלע דו כיוונית(גרף לא מכוון)
        void addEdge(int src, int dest, int weight);
        //פונקציה להוספת צלע חד כיוונית(לגרף מכוון)
        void addOneEdge(int src, int dest, int weight);
        //פונקציה להסרת צלע מהגרף(לשני הכיוונים אם הגרף לא מכוון)
        void removeEdge(int src, int dest);
        //פונקציה להדפסת הגרף לרשימת השכינויות
        void print_graph() const;
        //פונקציה שמחזירה את רשימת השכנים של הצומת
        Node* getNeighbors(int vertex) const;
        //פונקציה שמחזירה את מספר הצמתים שבגרף
        int getVertexCount() const;
        //פונקציה נוספת לקבלת מספר צמתים בגרף
        int getVertices() const;
        //פונקציה שמחזירה את רשימת השכינויות
        Node** getAdjList() const;
        //פונקציה המחזירה את כל הצלעות בגרף כמערך של Edge
        Edge* getAllEdges(int& edgeCount) const;
    

    };
}

#endif