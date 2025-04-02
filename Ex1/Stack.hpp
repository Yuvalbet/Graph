/*
Email: yuvali532@gmail.com
*/
#ifndef STACK_HPP
#define STACK_HPP

class Stack{
private:
    //Array for storing data
    int *arr;
    //The top index on the stack
    int top;
    //Stack size
    int capacity;

public:
    //constructor
    Stack(int capacity);
    //Destroys
    ~Stack();

    //insert into the stack
    void push(int value);
    //Remove from the stack
    int pop();
    //Check if the cartridge is empty
    bool isEmpty() const;
};

#endif