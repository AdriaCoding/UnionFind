#include "UnionFind.h"
#include <iostream>

UnionFind::UnionFind(int n, FindFunction f, UnionFunction u)
    : findFunc(f), unionFunc(u) {
    V.resize(n);
    for (int i = 0; i < n; ++i) {
        V[i] = i; // Initially, each element is its own P
    }
}

int UnionFind::Find(int x) {
    return findFunc(V, x);
}

void UnionFind::Union(int x, int y) {
    unionFunc(V, x, y, Find(x), Find(y));
}

void UnionFind::PrintContent() {
    int n = V.size();
    for (int i = 0; i < n; ++i) {
        std::cout << V[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << V[i] << " ";
    }
    std::cout << std::endl;
}
