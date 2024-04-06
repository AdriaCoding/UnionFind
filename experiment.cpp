#include <iostream>
#include <vector>
#include "UnionFind.h"

using namespace std;

int main() {
    int n = 10; 

    UnionFind QU_D(n, DeleteThisFind, QuickUnion);
    QU_D.Union(2, 4);
    QU_D.PrintContent();

    UnionFind QU_NC(n, NoCompressionFind_QU, QuickUnion);
    QU_NC.Union(2, 4);
    QU_NC.PrintContent();


}