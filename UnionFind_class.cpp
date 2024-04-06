#include "UnionFind.h"

UnionFind::UnionFind(int n, UnionMethod union_method, FindMethod find_method)
{
    V.resize(n);
    // Initialize vector according to the union method
    if (union_method == UnionMethod::QUICK_UNION){
        unionFunc = quick_union;        
        for (int i = 0; i < n; ++i) V[i] = i; 
    }
    else {
        for (int i = 0; i < n; ++i) V[i] = -1; 
        if (union_method == UnionMethod::RANK)
            unionFunc = union_by_rank;
        if (union_method == UnionMethod::WEIGHT)
            unionFunc = union_by_weight;
    }

    // Initialize FindMethod
    switch (find_method) {
        case FindMethod::NO_COMPRESSION:
            union_method == UnionMethod::QUICK_UNION
            ? findFunc = no_compression_find_4QU
            : findFunc = no_compression_find;
            break;
        case FindMethod::FULL_COMPRESSION:
            union_method == UnionMethod::QUICK_UNION
            ? findFunc = full_compression_find_4QU
            : findFunc = full_compression_find;
            break;        
        case FindMethod::PATH_SPLITTING:
            union_method == UnionMethod::QUICK_UNION
            ? findFunc = path_splitting_find_4QU
            : findFunc = path_splitting_find;
            break;
        case FindMethod::PATH_HALVING:
            switch (union_method){
                case UnionMethod::QUICK_UNION:
                    findFunc = path_halving_find_4QU;
                    break;
                
                case UnionMethod::RANK:
                    findFunc = path_halving_find_4UR;
                    break;
                case UnionMethod::WEIGHT:
                    findFunc = path_halving_find;
                    break;
            }
            break; 
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
