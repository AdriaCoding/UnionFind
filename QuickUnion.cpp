#include <iostream>
#include <vector>
using namespace std;

class QuickUnion {
private:
    vector<int> root;
public:
    QuickUnion(int n) : root(n) {
        n = n;
        for (int i = 0; i < n; i++) {
            root[i] = i;
        }
    }

    int Find(int x) {
        while (x != root[x]) {
            x = root[x];
        }
        return x;
    }

    void Union(int x, int y) {
        int rx = Find(x);
        int ry = Find(y);
        if (rx != ry){
            root[ry] = rx;
        }
    }

};

int main() {
    int i = 3, n = 10;
    QuickUnion P = QuickUnion(n);
    P.Union(2, 0);
    P.Union(1, 9);
    P.Union(1, 2);
    for(int i = 0; i < n; i++)
        cout << P.Find(i) << " ";


}