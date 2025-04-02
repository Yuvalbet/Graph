/*
Email: yuvali532@gmail.com
*/   
#ifndef UNIONFIND_HPP
#define UNIONFIND_HPP

namespace graph {

    // Data structure representing a subset in a union find structure
    struct Subset {
        //Pointer to the parent of the node (if it is itself then it is the root of the group)
        int parent;
        //Node degree
        int rank;
    };

    class UnionFind {
    private:
        //array of subgroups for group management
        Subset* subsets;
        //Number of nodes (groups at the beginning)
        int size;

    public:
        //Constructor - initializes the data structure for a given number of nodes
        UnionFind(int vertices);
        //Destroys - Frees the memory allocated to the subgroup array
        ~UnionFind();
        // Function to find the root of node i with router compression
        int find(int i);
        //Function to merge two groups by rank
        void unionSets(int x, int y);
    };
}

#endif