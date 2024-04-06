#include <iostream>
#include <vector>
#include "QU_NC.h"
using namespace std;

void UR_NC::init(int n) {
    P.resize(n);
    for (int i = 0; i < n; i++) {
        P[i] = -1;
    }
    nr_blocks = n;
}

int UR_NC::Find(int x) {
    while (P[x] >= 0) x = P[x];
    return x;
}

void UR_NC::Union(int x, int y) {
    int rx = Find(x);
    int ry = Find(y);
    if (rx != ry){
        if (P[rx] >= P[ry]) {
        // rx is the shortest
            P[ry] = min(P[ry], P[rx] - 1);
            P[rx] = ry;
        } else {
            P[rx] = min(P[rx], P[ry] - 1);
            P[rx] = ry;
        }
        --nr_blocks;
    }
}
void UR_NC::PrintFullData(){
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