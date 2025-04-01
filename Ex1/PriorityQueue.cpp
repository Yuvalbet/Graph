#include "PriorityQueue.hpp"
#include <iostream>

//בנאי של מחלקת התור עדיפויות
//אתחול המחסנית עם קיבולת מסויימת והקצאת זכרון למבנים פנימיים
PriorityQueue::PriorityQueue(int capacity){
    this->capacity = capacity;
    //ערימת מינימום מבוססת מערך
    heap = new PQNode[capacity];
    //מערך לשמירת מיקומי הצמתים בערימה
    positions = new int[capacity];
    size = 0;

    //זריקת שגיאה במקרה שהקצאת הזכרון נכשלה
    if(!heap || !positions){
        std::cout << "Error: Memory allocation failed in PriorityQueue .\n";
        delete[] heap;
        delete[] positions;
        heap = nullptr;
        positions = nullptr;
    }
        
}
    

//בנאי הורס המשחרר את הזכרון הדינמי
PriorityQueue::~PriorityQueue(){
    delete[] heap;
    delete[] positions;
}

//העלאת אלמנט בערימה עד שהמיקום שלו תקין לפי סדר העדיפויות
void PriorityQueue::heapifyUp(int index){
    while (index > 0){
        int parant = (index - 1) / 2;
        if (heap[index].priority >= heap[parant].priority)
            break;
        
        //החלפה בין הצומת להורה
        std::swap(heap[index], heap[parant]);
        positions[heap[index].vertex] = index;
        positions[heap[parant].vertex] = parant;
        index = parant;
        
    }
    
}

//הורדת אלמנט בערימה עד שהמיקום שלו תקין לפי סדר העדיפויות
void PriorityQueue::heapifyDown(int index){
    while (2* index+1 < size){
        int left = 2*index +1;
        int right = 2*index +2;
        int smallest = left;

        if(right < size && heap[right].priority < heap[left].priority)
        smallest = right;

        if(heap[index].priority <= heap[smallest].priority)
            break;

        std::swap(heap[index], heap[smallest]);
        positions[heap[index].vertex] = index;
        positions[heap[smallest].vertex] = smallest;
        index = smallest;
    } 
}

//הוספת צומת לתור העדיפויות
void PriorityQueue::push(int vertex, int priority){
    if(size >= capacity){
        //זריקת שגיאה מכיוון שהקיבולת מלאה כבר ואי אפשר להוסיף עוד איבר
        std::cout << "Error: PriorityQueue is full.\n";
        return;
    }
        
    heap[size] = {vertex, priority};
    positions[vertex] = size;
    heapifyUp(size);
    size++;
}

//הוצאת הצומת עם העדיפות הגבוהה ביותר(הערך הקטן ביותר)
int PriorityQueue::pop(){
    if(size == 0)
        return -1;

    int vertex = heap[0].vertex;
    size--;  // Reduce the size first

    if (size > 0) {  // Ensure there is still an element before accessing heap[0]
        heap[0] = heap[size];  // Move the last element to the root
        positions[heap[0].vertex] = 0;
        heapifyDown(0);
    }
    
    return vertex;
}

//בדיקה אם התור ריק
bool PriorityQueue::isEmpty() const{
    return size == 0;
}