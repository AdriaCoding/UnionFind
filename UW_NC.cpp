#include <iostream>
#include <vector>
using namespace std;

class UnionByWeight {
private:
    vector<int> P;
    int nr_blocks;
public:
    UnionByWeight(int n) : P(n) {
        for (int i = 0; i < n; i++) {
            P[i] = -1;
        }
        nr_blocks = n;
    }

    int Find(int x) {
        while (P[x] >= 0) x = P[x];
        return x;
    }

    void Union(int x, int y) {
        int rx = Find(x);
        int ry = Find(y);
        if (rx != ry){
            if (P[rx] >= P[ry]) {
            // rx is the smallest
                P[ry] += P[rx];
                P[rx] = ry;
            } else {
                P[rx] += P[ry];
                P[rx] = ry;
            }
            --nr_blocks;
        }
    }
    void PrintFullData(){
        int n = P.size();

        for(int i = 0; i < n-1; i++)
            cout << i << ", ";
        cout << n-1 << endl;

        for(int i = 0; i < n-1; i++)
            cout << P[i] << ", ";
        cout << P[n-1] << endl;

        for(int i = 0; i < n-1; i++)
            cout << Find(i) << ", ";
        cout << Find(n-1) << endl;
    }

};

int main() {
    int i = 3, n = 10;
    UnionByWeight P = UnionByWeight(n);
    P.Union(2, 8);
    P.Union(4, 2);
    P.Union(1, 8);
    P.PrintFullData();
}