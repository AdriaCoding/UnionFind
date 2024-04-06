#include <iostream>
#include <vector>
#include "UnionFind.h"

using namespace std;

int main() {
    int n = 10; 

    UnionFind QU_D(n, DeleteThisFind, UnionMethod::QUICK_UNION);
    QU_D.Union(2, 4);
    QU_D.PrintContent();

    UnionFind QU_NC(n, no_compression_find_for_quick_union, UnionMethod::QUICK_UNION);
    QU_NC.Union(2, 4);
    QU_NC.PrintContent();

    
    UnionFind UR_NC(n, no_compression_find, UnionMethod::RANK);
    UR_NC.Union(2, 4);
    UR_NC.PrintContent();

    UnionFind UR_FC(n, full_compression_find, UnionMethod::RANK);
    UR_FC.Union(2, 4);
    UR_FC.PrintContent();

    UnionFind UR_PS(n, path_splitting_find, UnionMethod::RANK);
    UR_PS.Union(2, 4);
    UR_PS.PrintContent();

    UnionFind UR_PH(n, path_halving_find, UnionMethod::RANK);


}