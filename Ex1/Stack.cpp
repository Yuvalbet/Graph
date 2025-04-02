/*
Email: yuvali532@gmail.com
*/
#include "Stack.hpp"
#include <iostream>

//Constructor - creates a stack with a given capacity
Stack::Stack(int capacity){
    //Save the capacity entered by the user
    this->capacity = capacity;
    //Allocate memory for the stack array
    arr = new int[capacity];
    //The stack is initially empty
    top = -1;
}

//Destructs-frees the memory allocated to the array
Stack::~Stack(){
    delete[]arr;
}

//Function to add an element to the stack
void Stack::push(int value){
    //Check if the stack is full
    if(top == capacity-1){
        std::cerr << "Stack overflow!" << std::endl;
        //If the buffer is full, no more elements can be added
        return;
    }
    //Increase top and add the value
    arr[++top] = value;
}

//Function to pop an element from the stack
int Stack::pop(){
    //Check if the cartridge is empty
    if (isEmpty()){
        std::cerr << "Stack underflow!" <<std::endl;
        //Returns an invalid value in case of an attempt to remove a member from an empty stack
        return -1;
    }
    //Return the top value and decrement the top
    return arr[top--];
    
}

//Function that checks if the stack is empty
bool Stack::isEmpty() const{
    return top == -1;
}