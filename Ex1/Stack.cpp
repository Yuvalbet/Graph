#include "Stack.hpp"
#include <iostream>

//בנאי- יוצר מחסנית עם קיבולת נתונה
Stack::Stack(int capacity){
    //שמירת הקיבולת שהמשתמש הזין
    this->capacity = capacity;
    //הקצאת זכרון למערך המחסנית
    arr = new int[capacity];
    //המחסנית בהתחלה ריקה
    top = -1;
}

//הורס-משחרר את הזיכרון שהוקצה למערך
Stack::~Stack(){
    delete[]arr;
}

//פונקציה להוספת איבר למחסנית
void Stack::push(int value){
    //בדיקה אם המחסנית מלאה
    if(top == capacity-1){
        std::cerr << "Stack overflow!" << std::endl;
        //אם המסנית מלאה, לא ניתן להוסיף עוד איברים
        return;
    }
    //מגדילים את top ומוסיפים את הערך
    arr[++top] = value;
}

//פונקציה להוצאת איבר מהמחסנית
int Stack::pop(){
    //בדיקה אם המחסנית ריקה
    if (isEmpty()){
        std::cerr << "Stack underflow!" <<std::endl;
        //מחזירים ערך לא חוקי במקרה של ניסיון להוציא איבר ממחסנית ריקה
        return -1;
    }
    //מחזירים את הערך העליון ומקטינים את הtop
    return arr[top--];
    
}

//פונקציה שבודקת אם המחסנית ריקה
bool Stack::isEmpty() const{
    return top == -1;
}