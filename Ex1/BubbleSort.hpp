/*
Email: yuvali532@gmail.com
*/
#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP

#include "Graph.hpp"

namespace graph {
    class BubbleSort {
    public:
        //Sorts an array of edges in ascending order by their weight
        static void sort(Edge* edges, int edgeCount);
    };
}

#endif