#include <iostream>
#include <vector>
#include <random>
#include "UnionFind.h"

using namespace std;

const int n = 8; // number of elements
const int m = n*(n-1) / 2; // number of pairs
// We will be taking measures n/del times. 
const int del = 4;

const UnionMethod union_methods[] = { 
    UnionMethod::QUICK_UNION,
    UnionMethod::RANK,
    UnionMethod::WEIGHT
};

vector<pair<int, int>> generateShuffledPairs(int n) {
    vector<pair<int, int>> pairs;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            pairs.push_back({i, j});
        }
    }
    random_device rd; // random number generator rd
    mt19937 g(rd()); // Mersenne Twister seeded with rd
    shuffle(pairs.begin(), pairs.end(), g);
    return pairs;
}

int TPL(UnionFind& uf){
    return uf.TotalPathLength();
}

int TPU(UnionFind& uf, FindMethod f){
    if (f == FindMethod::NO_COMPRESSION) return 0;
    if (f == FindMethod::PATH_HALVING){
        int TPU = 0;
        for (int i = 0; i < n; i++){
            TPU += uf.PathLength(i)/2;
        }
        return TPU;
    }
    // if it is Full Compression or Path-Splitting
    return TPL(uf) - uf.TotalNumberOfChildren();
}


int main() {
    vector<pair<int, int>> pairs = generateShuffledPairs(n);
    for (const auto& u : union_methods) {
        FindMethod f = FindMethod::PATH_HALVING;
        UnionFind UF(n, u, f); 

        for (int i = 0; i < m; i++) {
            if (i % del == 0) { // take measurements
                printf("TPL = %d  TPU = %d \n", TPL(UF), TPU(UF, f));
                UF.PrintContent();
            }
            int x = pairs[i].first;
            int y = pairs[i].second;
            UF.Union(x, y);
        }
    }
}