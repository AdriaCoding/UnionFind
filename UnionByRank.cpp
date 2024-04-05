#include <iostream>
#include <vector>
using namespace std;

class UnionByRank {
private:
    vector<int> root;
    vector<int> rank;
public:
    UnionByRank(int n) : root(n), rank(n) {
        for (int i = 0; i < n; i++) {
            root[i] = i;
            rank[i] = 0;
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
            if (rank[rx] > rank[ry]){
                root[ry] = rx;
            } else if (rank[rx] < rank[ry]){
                root[rx] = ry;
            } else {
                root[ry] = rx;
                rank[rx] += 1;
            }
        }
    }
    void PrintFullData(){
        int n = root.size();

        for(int i = 0; i < n-1; i++)
            cout << i << ", ";
        cout << n-1 << endl;

        for(int i = 0; i < n-1; i++)
            cout << root[i] << ", ";
        cout << root[n-1] << endl;

        for(int i = 0; i < n-1; i++)
            cout << rank[i] << ", ";
        cout << rank[n-1] << endl;

        for(int i = 0; i < n-1; i++)
            cout << Find(i) << ", ";
        cout << Find(n-1) << endl;
    }

};

int main() {
    int i = 3, n = 10;
    UnionByRank P = UnionByRank(n);
    P.Union(2, 0);
    P.Union(1, 4);
    P.Union(1, 0);
    P.Union(3, 4);
    P.PrintFullData();
}