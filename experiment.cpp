#include <iostream>
#include <vector>
#include <random>
#include "UnionFind.h"

using namespace std;

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
    if (f == FindMethod::FULL_COMPRESSION) 
        return TPL(uf) - uf.TotalNumberOfChildren();
    return 0;
}


int main() {
    int n = 8; // number of elements
    int m = n*(n-1) / 2; // number of pairs
    int del = 4; // number of checking points

    vector<pair<int, int>> pairs = generateShuffledPairs(n);

    for (const auto& u : union_methods) {
        FindMethod f = FindMethod::FULL_COMPRESSION;
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