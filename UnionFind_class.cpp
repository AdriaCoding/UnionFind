#include "UnionFind.h"

UnionFind::UnionFind(int n, UnionMethod union_method, FindMethod find_method)
{
    V.resize(n);
    if (union_method == UnionMethod::QUICK_UNION) {
        // Initialize UnionMethod
        unionFunc = quick_union;  
        // Root nodes point to themselves
        for (int i = 0; i < n; ++i) V[i] = i; 
        // Initialize the appropiate find method          
        switch (find_method) {
            case FindMethod::NO_COMPRESSION:
                findFunc = no_compression_find_4QU;
                name = "QU_NC";
                break;
            case FindMethod::FULL_COMPRESSION:
                findFunc = full_compression_find_4QU;
                name = "QU_FC";
                break;
            case FindMethod::PATH_SPLITTING:
                findFunc = path_splitting_find_4QU;
                name = "QU_PS";
                break;
            case FindMethod::PATH_HALVING:
                findFunc = path_halving_find_4QU;
                name = "QU_PH";
                break;
        }
    }
    else {
        // Initialize appropiate UnionMethod
        if (union_method == UnionMethod::RANK){
            unionFunc = union_by_rank;
            name = "UR_";
        }
        if (union_method == UnionMethod::WEIGHT){
            unionFunc = union_by_weight;
            name = "UW_";
        }
        // Root nodes point to -(weight/rank) of their tree
        for (int i = 0; i < n; ++i) V[i] = -1; 

        // Get the appropiate find method  
        switch (find_method) {
            case FindMethod::NO_COMPRESSION:
                findFunc = no_compression_find;
                name += "NC";
                break;
            case FindMethod::FULL_COMPRESSION:
                findFunc = full_compression_find;
                name += "FC";
                break;
            case FindMethod::PATH_SPLITTING:
                findFunc = path_splitting_find;
                name += "PS";
                break;
            case FindMethod::PATH_HALVING:
                findFunc = path_halving_find;
                name += "PH";
                break;
        }
    }
}

int UnionFind::Find(int x) {
    return findFunc(V, x);
}

void UnionFind::Union(int x, int y) {
    unionFunc(V, Find(x), Find(y));
}

void UnionFind::PrintContent() {
    int n = V.size();
    for (int i = 0; i < n; ++i) {
        if(V[i] >= 0) cout << " ";
        cout << V[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        if(Find(i) >= 0) cout << " ";
        cout << Find(i) << " ";
    }
    cout << endl << endl;
}
