#include <iostream>
#include <vector>
#include <random>
#include "UnionFind.h"

using namespace std;

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



int main() {
    int n = 8; // number of elements
    int m = n*(n-1) / 2; // number of pairs
    int del = 4; // number of checking points

    vector<pair<int, int>> pairs = generateShuffledPairs(n);

    UnionMethod u = UnionMethod::WEIGHT;
    FindMethod f = FindMethod::NO_COMPRESSION;
    UnionFind UF(n, u, f); 

    for (int i = 0; i < m; i++) {
        if (i % del == 0) { // take measurements
            UF.PrintContent();
        }
        int x = pairs[i].first;
        int y = pairs[i].second;
        UF.Union(x, y);
    }




}