#include <iostream>
#include <vector>
#include "UnionFind.h"


using namespace std;
int main() {
    int n = 8; 

    vector<UnionFind> ufs;

    UnionFind QU_NC(n, UnionMethod::QUICK_UNION, FindMethod::NO_COMPRESSION);   
    UnionFind QU_PH(n, UnionMethod::QUICK_UNION, FindMethod::PATH_SPLITTING);
    UnionFind QU_FC(n, UnionMethod::QUICK_UNION, FindMethod::FULL_COMPRESSION);
    UnionFind UR_NC(n, UnionMethod::RANK, FindMethod::NO_COMPRESSION);
    UnionFind UR_PH(n, UnionMethod::RANK, FindMethod::PATH_SPLITTING);
    UnionFind UR_FC(n, UnionMethod::RANK, FindMethod::FULL_COMPRESSION);

    ufs.push_back(QU_NC); ufs.push_back(QU_PH); ufs.push_back(QU_FC);
    ufs.push_back(UR_NC); ufs.push_back(UR_PH); ufs.push_back(UR_FC);
    
    for (auto& uf : ufs) {
        uf.Union(0, 1);
        uf.Union(2, 3);
        uf.Union(4, 5);
        uf.Union(6, 7);
        uf.Union(1, 3);
        uf.Union(5, 7);
        //uf.Union(3, 7);
        uf.Find(0);
        uf.PrintContent();
    }



}