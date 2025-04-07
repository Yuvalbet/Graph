/*
Email: yuvali532@gmail.com
*/   
#ifndef UNIONFIND_HPP
#define UNIONFIND_HPP

namespace graph {

    // Data structure representing a subset in a union find structure
    struct Subset {
        //Pointer to the parent of the node 
        int parent;
        //Node degree
        int rank;
    };

    class UnionFind {
    private:
        //array of subgroups for group management
        Subset* subsets;
        int size;

    public:
        //Constructor - initializes the data structure for a given number of nodes
        UnionFind(int vertices);
        //Destractor
        ~UnionFind();
        int find(int i);
        void unionSets(int x, int y);
    };
}

#endif