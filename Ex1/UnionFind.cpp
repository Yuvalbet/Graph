/*
Email: yuvali532@gmail.com
*/
#include "UnionFind.hpp"
#include <iostream>

namespace graph {

    //Initialize union find structure with an array of subsets
    UnionFind::UnionFind(int vertices) {
        size = vertices;
        //Creating an array of subsets
        subsets = new Subset[vertices];
        //Initialize each node to be its own parent and to rank zero
        for (int i = 0; i < vertices; i++) {
            //Each node starts as its own parent
            subsets[i].parent = i;
            //The initial rank is zero
            subsets[i].rank = 0;
        }
    }

    //Destractor
    UnionFind::~UnionFind() {
        delete[] subsets;
    }

    //Function to find the group's representative
    int UnionFind::find(int i) {
        if (subsets[i].parent != i)
            subsets[i].parent = find(subsets[i].parent);
        return subsets[i].parent;
    }
    
    //Function to merge 2 groups by rank
    void UnionFind::unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        //Union by ranking - connect the small tree to the large one
        if (subsets[rootX].rank < subsets[rootY].rank)
            subsets[rootX].parent = rootY;
        else if (subsets[rootX].rank > subsets[rootY].rank)
            subsets[rootY].parent = rootX;
        else {
            subsets[rootY].parent = rootX;
            //Increase the rank if they are equal
            subsets[rootX].rank++;
        }
    }
}