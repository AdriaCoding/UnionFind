#include <iostream>
#include <vector>
#include "UnionFind.h"

using namespace std;
int main() {
    int n = 10; 

    UnionFind QU_NC(n, UnionMethod::QUICK_UNION, FindMethod::NO_COMPRESSION);
    QU_NC.Union(2, 4);
    QU_NC.Union(3, 1);
    QU_NC.Union(7, 6);
    QU_NC.Union(0, 1);
    QU_NC.PrintContent();

    
    UnionFind UR_NC(n, UnionMethod::RANK, FindMethod::FULL_COMPRESSION);
    UR_NC.Union(2, 4);
    UR_NC.Union(3, 1);
    UR_NC.Union(7, 6);
    UR_NC.Union(0, 1);
    UR_NC.PrintContent();

}