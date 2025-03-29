#include "UnionFind.hpp"
#include <iostream>

namespace graph {

    UnionFind::UnionFind(int vertices) {
        size = vertices;
        subsets = new Subset[vertices];
        for (int i = 0; i < vertices; i++) {
            subsets[i].parent = i;
            subsets[i].rank = 0;
        }
    }

    UnionFind::~UnionFind() {
        delete[] subsets;
    }

    int UnionFind::find(int i) {
        if (subsets[i].parent != i)
            subsets[i].parent = find(subsets[i].parent);
        return subsets[i].parent;
    }

    void UnionFind::unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (subsets[rootX].rank < subsets[rootY].rank)
            subsets[rootX].parent = rootY;
        else if (subsets[rootX].rank > subsets[rootY].rank)
            subsets[rootY].parent = rootX;
        else {
            subsets[rootY].parent = rootX;
            subsets[rootX].rank++;
        }
    }
}