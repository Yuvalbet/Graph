#include "UnionFind.hpp"
#include <iostream>

namespace graph {

    //אתחול מבנה  union find עם מערך של תתי קבוצות(subsets)
    UnionFind::UnionFind(int vertices) {
        size = vertices;
        //יצירת מערך של קבוצות (subsets)
        subsets = new Subset[vertices];
        //אתחול  כל צומת להיות ההורה של עצמו ולדרגה אפס (rank)
        for (int i = 0; i < vertices; i++) {
            //כל צומת מתחיל כהורה של עצמו
            subsets[i].parent = i;
            //הדרגה ההתחלתית היא אפס
            subsets[i].rank = 0;
        }
    }
    //משחרר את הזכרון של המבנה בעת ההשמדה
    UnionFind::~UnionFind() {
        delete[] subsets;
    }
    //פונקציה למציאת הנציג של הקבוצה
    int UnionFind::find(int i) {
        if (subsets[i].parent != i)
            subsets[i].parent = find(subsets[i].parent);
        return subsets[i].parent;
    }
    //פונקציה לאיחוד 2 קבוצות לפי הדרגה
    void UnionFind::unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        //איחוד לפי דירוג- מחברים את העץ הקטן לגדול
        if (subsets[rootX].rank < subsets[rootY].rank)
            subsets[rootX].parent = rootY;
        else if (subsets[rootX].rank > subsets[rootY].rank)
            subsets[rootY].parent = rootX;
        else {
            subsets[rootY].parent = rootX;
            //מגדילים את הדרגה אם הם שווים
            subsets[rootX].rank++;
        }
    }
}