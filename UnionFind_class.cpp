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

    switch (union_method) {
        case UnionMethod::QUICK_UNION:
        // Initialize vector according to the union method
            for (int i = 0; i < n; ++i) V[i] = i; 
        // Initialize UnionMethod
            unionFunc = quick_union;  
        // Get the appropiate find method          
            switch (find_method) {
                case FindMethod::NO_COMPRESSION:
                    findFunc = no_compression_find_4QU;
                    break;
                case FindMethod::FULL_COMPRESSION:
                    findFunc = full_compression_find_4QU;
                    break;
                case FindMethod::PATH_SPLITTING:
                    findFunc = path_splitting_find_4QU;
                    break;
                case FindMethod::PATH_HALVING:
                    findFunc = path_halving_find_4QU;
                    break;
            }
            break;
        case UnionMethod::RANK:
        // Initialize vector according to the union method
            for (int i = 0; i < n; ++i) V[i] = -1; 
        // Initialize UnionMethod
            unionFunc = union_by_rank;  
        // Get the appropiate find method  
            switch (find_method) {
                case FindMethod::NO_COMPRESSION:
                    findFunc = no_compression_find;
                    break;
                case FindMethod::FULL_COMPRESSION:
                    findFunc = full_compression_find;
                    break;
                case FindMethod::PATH_SPLITTING:
                    findFunc = path_splitting_find_4UR;
                    break;
                case FindMethod::PATH_HALVING:
                    findFunc = path_halving_find_4UR;
                    break;
            }
            break;
        case UnionMethod::WEIGHT:
        // Initialize vector according to the union method
            for (int i = 0; i < n; ++i) V[i] = -1; 
        // Initialize UnionMethod
            unionFunc = union_by_weight;  
        // Get the appropiate find method 
            switch (find_method) {
                case FindMethod::NO_COMPRESSION:
                    findFunc = no_compression_find;
                    break;
                case FindMethod::FULL_COMPRESSION:
                    findFunc = full_compression_find;
                    break;
                case FindMethod::PATH_SPLITTING:
                    findFunc = path_splitting_find;
                    break;
                case FindMethod::PATH_HALVING:
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
