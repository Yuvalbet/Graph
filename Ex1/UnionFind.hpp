#ifndef UNIONFIND_HPP
#define UNIONFIND_HPP

namespace graph {

    struct Subset {
        int parent;
        int rank;
    };

    class UnionFind {
    private:
        Subset* subsets;
        int size;

    public:
        UnionFind(int vertices);
        ~UnionFind();

        int find(int i);
        void unionSets(int x, int y);
    };
}

#endif