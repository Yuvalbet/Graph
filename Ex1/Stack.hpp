#ifndef STACK_HPP
#define STACK_HPP

class Stack{
private:
    //מערך לאחסון הנתונים
    int *arr;
    //האינדקס העליון במחסנית
    int top;
    //גודל המחסנית
    int capacity;

public:
    //בנאי
    Stack(int capacity);
    //הורס
    ~Stack();

    //הכנסה למחסנית
    void push(int value);
    //הוצאה מהמחסנית
    int pop();
    //בדיקה אם המחסנית ריקה 
    bool isEmpty() const;
};

#endif