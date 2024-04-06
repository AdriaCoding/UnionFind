#include <vector>
#include <algorithm> // for std::min
#include <cstdio> // for printf

using Vec = std::vector<int>;

// NO COMPRESSION implementations for FIND

int no_compression_find (Vec& P, int x) {
    while (P[x] >= 0) x = P[x];
    return x;
}
int no_compression_find_4QU(Vec& root, int x) {
    while (x != root[x]) {
        x = root[x];
    }
    return x;
}

// FULL COMPRESSION implementations for FIND

int full_compression_find (Vec& P, int x) {
    if (P[x] < 0) return x;

    P[x] = full_compression_find(P, P[x]);
    return P[x];
}

int full_compression_find_4QU (Vec& root, int x) {
    if (root[x] == x) return x;

    root[x] = full_compression_find_4QU(root, root[x]);
    return root[x];
}

// PATH SPLITTING heuristic implementation for FIND

int path_splitting_find (Vec& P, int x) {
    while (P[x] >= 0){
        if (P[P[x]] < 0){
            return P[x];
        }
        int aux = P[x];
        P[x] = P[P[x]];
        x = aux;
    }
    return x;
}
int path_splitting_find_4UR (Vec& P, int x) {
    //int rank_decrement = 0;
    while (P[x] >= 0){
        if (P[P[x]] < 0){
            return P[x];
        }
        int aux = P[x];
        P[x] = P[P[x]];
        x = aux;
    }
    return x;
}
int path_splitting_find_4QU (Vec& P, int x) {
    while (P[x] != x){
        int aux = P[x];
        P[x] = P[P[x]];
        x = aux;
    }
    return x;
}

// PATH HALVING heuristic implementation for FIND

int path_halving_find (Vec& P, int x) {
    while (P[x] >= 0){
        if (P[P[x]] < 0){
            return P[x];
        }
        P[x] = P[P[x]];
        x = P[x];
    }
    return x;
}
int path_halving_find_4UR (Vec& P, int x) {
    int rank_decrement = 0;
    while (P[x] >= 0){
        if (P[P[x]] < 0){
            P[P[x]] += rank_decrement;
            return P[x];
        }
        P[x] = P[P[x]];
        x = P[x];
        rank_decrement++;
    }
    return x;
}
int path_halving_find_4QU (Vec& P, int x) {
    while (P[x] != x){
        P[x] = P[P[x]];
        x = P[x];
    }
    return x;
}

// Implementations for UNION

void quick_union(Vec& root, int rx, int ry) {
    if (rx != ry){
        root[ry] = rx;
    }
}
void union_by_rank(Vec& P, int rx, int ry) {
    if (rx != ry){
        if (P[rx] >= P[ry]) {
        // rx is the shortest
            P[ry] = std::min(P[ry], P[rx] - 1);
            P[rx] = ry;
        } else {
            P[rx] = std::min(P[rx], P[ry] - 1);
            P[ry] = rx;
        }
    }
}
void union_by_weight(Vec& P, int rx, int ry) {
    if (rx != ry){
        if (P[rx] >= P[ry]) {
        // rx is the shortest
            P[ry] += P[rx];
            P[rx] = ry;
        } else {
            P[rx] += P[ry];
            P[ry] = rx;
        }
    }
}
