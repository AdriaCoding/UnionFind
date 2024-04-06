#include <vector>
#include <iostream>
#include <functional> // for std::function
#include <algorithm> // for std::min


using FindFunction = std::function<int(const std::vector<int>&, int)>;
using UnionFunction = std::function<void(std::vector<int>&, int, int, int, int)>;
using namespace std;

class UnionFind {
private:
    vector<int> V;
    FindFunction findFunc;
    UnionFunction unionFunc;
public:
    UnionFind(int n, FindFunction f, UnionFunction u)
        : findFunc(f), unionFunc(u) {
        V.resize(n);
        for (int i = 0; i < n; ++i) {
            V[i] = i; // Initially, each element is its own P
        }
    }

    int Find(int x) {
        return findFunc(V, x);
    }

    void Union(int x, int y) {
        unionFunc(V, x, y, Find(x), Find(y));
    }

    void PrintContent(){
        int n = V.size();
        for (int i = 0; i < n; ++i) {
            cout << V[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < n; ++i) {
            cout << V[i] << " ";
        }
        cout << endl;
    }
};

// Find implementations

int DeleteThisFind(const std::vector<int>& root, int x){
    return root.size();
}
int NoCompressionFind_QU(const std::vector<int>& root, int x) {
    while (x != root[x]) {
        x = root[x];
    }
    return x;
}
int NoCompressionFind_UR(const std::vector<int>& P, int x) {
    while (P[x] >= 0) x = P[x];
    return x;
}

// Union implementations

void QuickUnion(std::vector<int>& root, int x, int y, int rx, int ry) {
    if (rx != ry){
        root[ry] = rx;
    }
}
void UnionByRank(std::vector<int>& P, int x, int y, int rx, int ry) {
    if (rx != ry){
        if (P[rx] >= P[ry]) {
        // rx is the shortest
            P[ry] = std::min(P[ry], P[rx] - 1);
            P[rx] = ry;
        } else {
            P[rx] = std::min(P[rx], P[ry] - 1);
            P[rx] = ry;
        }
        //--nr_blocks;
    }
}

// Example usage:
int main() {
    int n = 10; 

    UnionFind QU_D(n, DeleteThisFind, QuickUnion);
    QU_D.Union(2, 4);
    QU_D.PrintContent();

    UnionFind QU_NC(n, NoCompressionFind_QU, QuickUnion);
    QU_NC.Union(2, 4);
    QU_NC.PrintContent();


}