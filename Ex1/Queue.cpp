#include "Queue.hpp"
#include <iostream>

//בנאי של המחלקה Queue - מאתחל תור בגודל נתון
Queue::Queue(int capacity){
    //שמירת הקיבולת של התור
    this->capacity = capacity;
    //הקצאת זיכרון למערך שמחזיק את הנתונים
    arr = new int[capacity];
    //מצביע לתחילת התור
    front = 0;
    //מצביע לסוף התור (מתחיל ב-1- כי אין אברים)
    rear = -1;
    //מספר האיברים בתור
    size = 0;
}
//הורס- משחרר את הזכרון שהוקצה דינאמית
Queue::~Queue(){
    //שחרור המערך הדינאמי
    delete[]arr;
}
//פונקציה להוספת ערך לסוף התור
void Queue::enqueue(int value){
    //בדיקה אם התור מלא
    if (isFull()){
        std::cerr << "Queue is full!" << std::endl;
        return;
    }
    //הזזת הrear בצורה מעגלית
    rear = (rear + 1) % capacity;
    //הכנסה של הערך למקום הפנוי
    arr[rear] = value;
    //עדכון גודל התור
    size++;
}
//פונקציה לשליפת הערך מראש התור והסרתו
int Queue::dequeue(){
    //בדיקה אם התור ריק
    if (isEmpty()){
        std::cerr << "Queue is empty!" <<std::endl;
        //ערך חזרה מיוחד שמציין שהתור ריק
        return -1;
    }
    //שמירת הערך שבראש התור
    int value = arr[front];
    //הזזת הfront בצורה מעגלית
    front = (front + 1) % capacity;
    //עדכון גודל התור
    size--;
    //החזרת הערך שנמחק
    return value;
}
//פונקציה שבודקת האם התור ריק
bool Queue::isEmpty() const{
    return size == 0;
}
//פונקציה שבודקת האם התור מלא
bool Queue::isFull() const{
    //מחזירה true אם התור הגיע לקיבולת המקסימלית
    return size == capacity;
}