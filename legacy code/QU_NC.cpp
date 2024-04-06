#include <iostream>
#include <vector>

#include "QU_NC.h"

using namespace std;

void QU_NC::init(int n) {
    root.resize(n);
    for (int i = 0; i < n; i++) {
        root[i] = i;
    }
}

int QU_NC::Find(int x) {
    while (x != root[x]) {
        x = root[x];
    }
    return x;
}

void QU_NC::Union(int x, int y) {
    int rx = Find(x);
    int ry = Find(y);
    if (rx != ry){
        root[ry] = rx;
    }
}
