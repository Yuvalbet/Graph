/*
Email: yuvali532@gmail.com
*/
#include "BubbleSort.hpp"
#include <iostream>

namespace graph {

    void BubbleSort::sort(Edge* edges, int edgeCount) {
        for (int i = 0; i < edgeCount - 1; i++) {
            for (int j = 0; j < edgeCount - i - 1; j++) {
                if (edges[j].weight > edges[j + 1].weight) {
                    // Swapping two edges if their order is wrong
                    Edge temp = edges[j];
                    edges[j] = edges[j + 1];
                    edges[j + 1] = temp;
                }
            }
        }
    }
}