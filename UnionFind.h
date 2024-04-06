#ifndef UNION_FIND_H
#define UNION_FIND_H

#include <vector>
#include <functional>
#include <algorithm> // for std::min 
#include <iostream>

using namespace std;

// Define function pointer types for Find and Union functions
using Vec = std::vector<int>;
using FindFunction = std::function<int(std::vector<int>&, int)>;
using UnionFunction = std::function<void(std::vector<int>&, int, int)>;

enum class UnionMethod {
    QUICK_UNION,
    RANK,
    WEIGHT
};
enum class FindMethod {
    NO_COMPRESSION,
    FULL_COMPRESSION,
    PATH_SPLITTING,
    PATH_HALVING
};

class UnionFind {
private:
    Vec V;
    FindFunction findFunc;
    UnionFunction unionFunc;

public:
    UnionFind(int n, UnionMethod u, FindMethod f);

    int Find(int x);

    void Union(int x, int y);

    void PrintContent();
};

// Function declarations of UnionFind_methods.cpp
int no_compression_find(Vec& P, int x);
int no_compression_find_4QU(Vec& root, int x);
int full_compression_find (Vec& P, int x);
int full_compression_find_4QU (Vec& P, int x);
int path_splitting_find (Vec& P, int x);
int path_splitting_find_4QU (Vec& P, int x);
int path_halving_find (Vec& P, int x);
int path_halving_find_4QU (Vec& P, int x);


void quick_union(Vec& root, int rx, int ry);
void union_by_rank(Vec& P, int rx, int ry);
void union_by_weight(Vec& P, int rx, int ry);

#endif // UNION_FIND_H
