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
using UnionFunction = std::function<void(std::vector<int>&, int, int, int, int)>;

enum class UnionMethod {
    QUICK_UNION,
    RANK,
    WEIGHT
};

class UnionFind {
private:
    Vec V;
    FindFunction findFunc;
    UnionFunction unionFunc;

public:
    UnionFind(int n, FindFunction f, UnionMethod u);

    int Find(int x);

    void Union(int x, int y);

    void PrintContent();
};

// Function declarations for UnionFunctions.cpp
int DeleteThisFind(Vec& root, int x);
int no_compression_find(Vec& P, int x);
int no_compression_find_for_quick_union(Vec& root, int x);
int full_compression_find (Vec& P, int x);
int path_splitting_find (Vec& P, int x);
int path_halving_find (Vec& P, int x);

void quick_union(Vec& root, int x, int y, int rx, int ry);
void union_by_rank(Vec& P, int x, int y, int rx, int ry);
void union_by_weight(Vec& P, int x, int y, int rx, int ry);

#endif // UNION_FIND_H
