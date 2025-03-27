#include "Stack.hpp"
#include <iostream>

Stack::Stack(int capacity){
    this->capacity = capacity;
    arr = new int[capacity];
    //המחסנית בהתחלה ריקה
    top = -1;
}

Stack::~Stack(){
    delete[]arr;
}

void Stack::push(int value){
    if(top == capacity-1){
        std::cerr << "Stack overflow!" << std::endl;
        return;
    }
    arr[++top] = value;
}

int Stack::pop(){
    if (isEmpty()){
        std::cerr << "Stack underflow!" <<std::endl;
        return -1;
    }
    return arr[top--];
    
}

bool Stack::isEmpty() const{
    return top == -1;
}