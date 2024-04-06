#include <vector>
#include <algorithm> // for std::min

using Vec = std::vector<int>;

// Find implementations

int DeleteThisFind(Vec& root, int x){
    return root.size();
}
int no_compression_find_4QU(Vec& root, int x) {
    while (x != root[x]) {
        x = root[x];
    }
    return x;
}

int no_compression_find (Vec& P, int x) {
    while (P[x] >= 0) x = P[x];
    return x;
}
int full_compression_find (Vec& P, int x) {
    if (P[x] < 0) return x;

    P[x] = full_compression_find(P, P[x]);
    return P[x];
}
int path_splitting_find (Vec& P, int x) {
    int parent = P[x];
    if (P[parent] < 0) return parent;

    P[x] = P[parent]; //point to grandparent
    return path_splitting_find(P, parent);
}
int path_halving_find (Vec& P, int x) {
    return 0;
}

// Union implementations

void quick_union(Vec& root, int x, int y, int rx, int ry) {
    if (rx != ry){
        root[ry] = rx;
    }
}
void union_by_rank(Vec& P, int x, int y, int rx, int ry) {
    if (rx != ry){
        if (P[rx] >= P[ry]) {
        // rx is the shortest
            P[ry] = std::min(P[ry], P[rx] - 1);
            P[rx] = ry;
        } else {
            P[rx] = std::min(P[rx], P[ry] - 1);
            P[rx] = ry;
        }
    }
}
void union_by_weight(Vec& P, int x, int y, int rx, int ry) {
    if (rx != ry){
        if (P[rx] >= P[ry]) {
        // rx is the shortest
            P[ry] += P[rx];
            P[rx] = ry;
        } else {
                P[rx] += P[ry];
            P[rx] = ry;
        }
    }
}
