#ifndef UNIONFIND_HPP
#define UNIONFIND_HPP

namespace graph {

    // מבנה נתונים המייצג תת קבוצה במבנה union find
    struct Subset {
        //מצביע להורה של הצומת (אם הוא עצמו אז הוא שורש הקבוצה)
        int parent;
        //דרגת הצומת
        int rank;
    };

    class UnionFind {
    private:
        //מערך של תת קבוצות לניהול הקבוצות
        Subset* subsets;
        //מספר הצמתים (הקבוצות בהתחלה)
        int size;

    public:
        //בנאי-מאתחל את מבנה הנתונים עבור מספר נתון של צמתים
        UnionFind(int vertices);
        //הורס- משחרר את הזכרון שהוקצה למערך התת קבוצות
        ~UnionFind();
        // פונקציה למציאת השורש של צומת i עם דחיסת נתבים
        int find(int i);
        //פונקציה לאיחוד שתי קבוצות לפי דרגה
        void unionSets(int x, int y);
    };
}

#endif