#include "UnionFind.h"

UnionFind::UnionFind(int n, FindFunction f, UnionFunction u, VectorMeaning meaning = VectorMeaning::RANK)
    : findFunc(f), unionFunc(u) 
{
    V.resize(n);
    if (meaning == VectorMeaning::ROOT){
        for (int i = 0; i < n; ++i) {
            V[i] = i; 
        }
    }
    else {
        for (int i = 0; i < n; ++i) {
            V[i] = -1; 
        }
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
