#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP

#include "Graph.hpp"

namespace graph {
    //מחלקה המספקת אלגוריתם מיון בועות למיון מערך של קשתות בגרף
    class BubbleSort {
    public:
        //ממיין מערך של קשתות בסדר עולה לפי משקלן
        static void sort(Edge* edges, int edgeCount);
    };
}

#endif