/*
Email: yuvali532@gmail.com
*/
#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP

#include "Graph.hpp"

namespace graph {
    //A class that provides a bubble sort algorithm for sorting an array of edges in a graph
    class BubbleSort {
    public:
        //Sorts an array of edges in ascending order by their weight
        static void sort(Edge* edges, int edgeCount);
    };
}

#endif