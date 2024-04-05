#include <iostream>
#include <vector>
#include "QU_NC.h"

using namespace std;

int main(){
    int n = 10;
    QU_NC T;
    T.init(n);
    T.Union(2, 0);
    for(int i = 0; i < n; i++)
        cout << T.Find(i) << " ";
}