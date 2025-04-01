#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

struct PQNode{
    int vertex;
    int priority;
};

class PriorityQueue{
private:
    //מערך המייצג את ערימת המינימום 
    PQNode* heap;
    //מערך השומר את מיקומי הקודקודים בערימה
    int* positions;
    //גודל הערימה הנוכחי
    int size;
    int capacity;

    void heapifyUp(int index);
    void heapifyDown(int index);


public:
    //בנאי
    PriorityQueue(int capacity);
    //הורס
    ~PriorityQueue();

    //הוספת איבר לתור העדיפויות
    void push(int vertex,int priority);
    //הוצאת הקודקוד עם העדיפות הגבוהה ביותר (הערך הנמוך ביותר)
    int pop();
    //בדיקה אם התור ריק
    bool isEmpty() const;
};

#endif