#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include "UnionFind.h"

using namespace std;

const int n = 10000; // number of elements
const int m = n*(n-1) / 2; // number of pairs
// We will be taking measures m/del times. 
const int del = n/100;

const UnionMethod union_methods[] = { 
    UnionMethod::QUICK_UNION,
    UnionMethod::RANK,
    UnionMethod::WEIGHT
};
const FindMethod find_methods[] = {
    FindMethod::NO_COMPRESSION,
    FindMethod::FULL_COMPRESSION,
    FindMethod::PATH_SPLITTING,
    FindMethod::PATH_HALVING
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

    string TPL_filename = "data/dataTPL_n" + to_string(n) + "_del" + to_string(del) + ".csv";
    string TPU_filename = "data/dataTPU_n" + to_string(n) + "_del" + to_string(del) + ".csv";

    ofstream TPL_file(TPL_filename);
    ofstream TPU_file(TPU_filename);

/*     TPL_file << "name"; TPU_file << "name";
    for (int i = 0; i <m/del; i++){
        TPL_file << "," << del*i;
        TPU_file << "," << del*i;
    }
    TPL_file << endl; TPU_file << endl;
 */
    for (const auto& f: find_methods){   
        for (const auto& u : union_methods) {
            UnionFind UF(n, u, f); 
            TPL_file << UF.name;
            TPU_file << UF.name;

            for (int i = 0; i < m; i++) {
                if (i % del == 0 and i > 5) { // take measurements
                    TPL_file << "," << (float)TPL(UF)/(float)i;
                    TPU_file << "," << (float)TPU(UF, f)/(float)i;
                }
                if (UF.AllJoined()) {
                    cout << " Union Find ~ " << UF.name;
                    cout << " ~ is all-connected in " << i;
                    cout << " steps." << endl;
                    break;
                }
                UF.Union(pairs[i].first, pairs[i].second);
            }
            TPL_file << endl;
            TPU_file << endl;  
        }
    }
}