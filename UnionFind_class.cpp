#include "UnionFind.h"

UnionFind::UnionFind(int n, FindFunction f, UnionMethod union_method)
    : findFunc(f)
{
    V.resize(n);
    switch (union_method) {
        case UnionMethod::QUICK_UNION:
            unionFunc = quick_union;
            for (int i = 0; i < n; ++i) {
                V[i] = i; 
            }
            break;
        case UnionMethod::RANK:
            unionFunc = union_by_rank;
            for (int i = 0; i < n; ++i) {
                V[i] = -1; 
            }
            break;
        case UnionMethod::WEIGHT:
            unionFunc = union_by_weight;
            for (int i = 0; i < n; ++i) {
                V[i] = -1; 
            }
            break;
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
