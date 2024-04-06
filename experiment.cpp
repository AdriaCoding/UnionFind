#include <iostream>
#include <vector>
#include "UnionFind.h"

using namespace std;
int main() {
    int n = 10; 

    vector<UnionFind> ufs;

    UnionFind QU_NC(n, UnionMethod::QUICK_UNION, FindMethod::NO_COMPRESSION);   
    UnionFind QU_FC(n, UnionMethod::QUICK_UNION, FindMethod::FULL_COMPRESSION);
    UnionFind UR_NC(n, UnionMethod::WEIGHT, FindMethod::NO_COMPRESSION);
    UnionFind UR_FC(n, UnionMethod::WEIGHT, FindMethod::FULL_COMPRESSION);
    ufs.push_back(QU_NC); ufs.push_back(QU_FC); ufs.push_back(UR_NC); ufs.push_back(UR_FC);
    for (auto& uf : ufs) {
        uf.Union(1, 0); 
        uf.Union(2, 3); 
        uf.Union(4, 5); 
        uf.Union(6, 7);
        uf.Union(0, 2);
        uf.Union(4, 6);
        uf.Union(0, 2);
        uf.Union(3, 4);
        uf.Union(7, 7);
        uf.PrintContent();
    }



}