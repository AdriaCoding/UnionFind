#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
private:
    vector<int> root;
public:
    UnionFind(int n) : root(n) {
        n = n;
        for (int i = 0; i < n; i++) {
            root[i] = i;
        }
    }

    int Find(int x) {
        return root[x];
    }

    void Union(int x, int y) {
        int rx = Find(x);
        int ry = Find(y);
        if (rx != ry){
            int n = root.size();
            for (int i = 0; i < n; i++){
                if (root[i] == rx) {
                    root[i] = y;
                }
            }
        }
    }

};

int main() {
    int i = 3, n = 4;
    UnionFind P = UnionFind(n);
    P.Union(2, 0);
    for(int i = 0; i < n; i++)
        cout << P.Find(i) << " ";


}