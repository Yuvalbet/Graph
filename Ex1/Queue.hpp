#ifndef QUEUE_HPP
#define QUEUE_HPP

class Queue{

private:

    //מערך לאחסון נתונים
    int *arr;
    //גודל מקסימלי של התור
    int capacity;
    //אינדקס ההתחלה של התור
    int front;
    //אינדקס הסוף של התור
    int rear;
    //מספר האלמנטים בתור
    int size;

public:
    
    //בנאי
    Queue(int capacity);
    //הורס
    ~Queue();

    //הוספה לתור
    void enqueue(int value);
    //הסרה מהתור
    int dequeue();
    //בדיקה אם התור ריק
    bool isEmpty() const;
    //בדיקה אם התור מלא
    bool isFull() const;

};

#endif