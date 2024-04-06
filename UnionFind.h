#ifndef UNION_FIND_H
#define UNION_FIND_H

#include <vector>
#include <functional>
#include <algorithm> // for std::min 
#include <iostream>

// Define function pointer types for Find and Union functions
using FindFunction = std::function<int(const std::vector<int>&, int)>;
using UnionFunction = std::function<void(std::vector<int>&, int, int, int, int)>;

class UnionFind {
private:
    std::vector<int> V;
    FindFunction findFunc;
    UnionFunction unionFunc;

public:
    UnionFind(int n, FindFunction f, UnionFunction u);

    int Find(int x);

    void Union(int x, int y);

    void PrintContent();
};

// Function declarations for UnionFunctions.cpp
int DeleteThisFind(const std::vector<int>& root, int x);
int no_compression_find_for_quick_union(const std::vector<int>& root, int x);
void quick_union(std::vector<int>& root, int x, int y, int rx, int ry);

#endif // UNION_FIND_H
