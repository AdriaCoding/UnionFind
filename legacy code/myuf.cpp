#include <iostream>
#include <vector>

using namespace std;

const int N = 100;
int n;
int uf[N];

void init(){
    for(int i=0; i<N; i++)
        uf[i] = i;
} 

int main(int argc){
    init();
    
}