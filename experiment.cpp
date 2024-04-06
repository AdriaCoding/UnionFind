#include <iostream>
#include <vector>
#include "UnionFind.h"

using namespace std;

int main() {
    int n = 10; 

    UnionFind QU_D(n, DeleteThisFind, quick_union, VectorMeaning::ROOT);
    QU_D.Union(2, 4);
    QU_D.PrintContent();

    UnionFind QU_NC(n, no_compression_find_for_quick_union, quick_union, VectorMeaning::ROOT);
    QU_NC.Union(2, 4);
    QU_NC.PrintContent();

    
    UnionFind UR_NC(n, no_compression_find, union_by_rank, VectorMeaning::RANK);
    UR_NC.Union(2, 4);
    UR_NC.PrintContent();


}