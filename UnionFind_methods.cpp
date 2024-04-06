#include <vector>
#include <iostream>
#include <functional> // for std::function
#include <algorithm> // for std::min

// Find implementations

int DeleteThisFind(const std::vector<int>& root, int x){
    return root.size();
}
int no_compression_find_for_quick_union(const std::vector<int>& root, int x) {
    while (x != root[x]) {
        x = root[x];
    }
    return x;
}
int no_compression_find(const std::vector<int>& P, int x) {
    while (P[x] >= 0) x = P[x];
    return x;
}

// Union implementations

void quick_union(std::vector<int>& root, int x, int y, int rx, int ry) {
    if (rx != ry){
        root[ry] = rx;
    }
}
void union_by_rank(std::vector<int>& P, int x, int y, int rx, int ry) {
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
