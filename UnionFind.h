#ifndef UNION_FIND_H
#define UNION_FIND_H

#include <vector>
#include <functional>
#include <algorithm> // for std::min 
#include <iostream>

using namespace std;

// Define function pointer types for Find and Union functions
using Vec = std::vector<int>;
using FindFunction = std::function<int(const std::vector<int>&, int)>;
using UnionFunction = std::function<void(std::vector<int>&, int, int, int, int)>;

enum class VectorMeaning {
    ROOT,
    RANK,
    WEIGHT
};

class UnionFind {
private:
    Vec V;
    FindFunction findFunc;
    UnionFunction unionFunc;

public:
    UnionFind(int n, FindFunction f, UnionFunction u, VectorMeaning m);

    int Find(int x);

    void Union(int x, int y);

    void PrintContent();
};

// Function declarations for UnionFunctions.cpp
int DeleteThisFind(const Vec& root, int x);
int no_compression_find(const Vec& P, int x);
int no_compression_find_for_quick_union(const Vec& root, int x);

void quick_union(Vec& root, int x, int y, int rx, int ry);
void union_by_rank(Vec& P, int x, int y, int rx, int ry);

#endif // UNION_FIND_H
