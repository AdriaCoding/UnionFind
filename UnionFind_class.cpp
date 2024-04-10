#include "UnionFind.h"

UnionFind::UnionFind(int n, UnionMethod union_method, FindMethod find_method)
{
    V.resize(n); n_blocks = n;

    if (union_method == UnionMethod::QUICK_UNION) {
        // Initialize UnionMethod
        unionFunc = quick_union;  
        // Root nodes point to themselves
        for (int i = 0; i < n; ++i) V[i] = i; 
        // Initialize the appropiate find method          
        switch (find_method) {
            case FindMethod::NO_COMPRESSION:
                findFunc = no_compression_find_4QU;
                name = "QU_NC";
                break;
            case FindMethod::FULL_COMPRESSION:
                findFunc = full_compression_find_4QU;
                name = "QU_FC";
                break;
            case FindMethod::PATH_SPLITTING:
                findFunc = path_splitting_find_4QU;
                name = "QU_PS";
                break;
            case FindMethod::PATH_HALVING:
                findFunc = path_halving_find_4QU;
                name = "QU_PH";
                break;
        }
    }
    else {
        // Initialize appropiate UnionMethod
        if (union_method == UnionMethod::RANK){
            unionFunc = union_by_rank;
            name = "UR_";
        }
        if (union_method == UnionMethod::WEIGHT){
            unionFunc = union_by_weight;
            name = "UW_";
        }
        // Root nodes point to -(weight/rank) of their tree
        for (int i = 0; i < n; ++i) V[i] = -1; 

        // Get the appropiate find method  
        switch (find_method) {
            case FindMethod::NO_COMPRESSION:
                findFunc = no_compression_find;
                name += "NC";
                break;
            case FindMethod::FULL_COMPRESSION:
                findFunc = full_compression_find;
                name += "FC";
                break;
            case FindMethod::PATH_SPLITTING:
                findFunc = path_splitting_find;
                name += "PS";
                break;
            case FindMethod::PATH_HALVING:
                findFunc = path_halving_find;
                name += "PH";
                break;
        }
    }
}

int UnionFind::Find(int x) {
    return findFunc(V, x);
}

void UnionFind::Union(int x, int y) {
    int rx = Find(x);
    int ry = Find(y);
    // If two different blocks are merged,
    // decrement the counter of blocks by 1.
    if (rx != ry) {
        unionFunc(V, rx, ry);
        --n_blocks;
    }
}

int UnionFind::PathLength(int x){
    int distance_to_representative = 0;
    while (V[x] >= 0 && V[x] != x)
    {   
        x = V[x];
        distance_to_representative++;
    }
    return distance_to_representative;
}
int UnionFind::TotalPathLength(){
    int n = V.size();
    int total_length = 0;
    for (int x = 0; x < n; ++x)
        total_length += PathLength(x);
    return total_length;
}

int UnionFind::TotalNumberOfChildren(){
    return V.size() - n_blocks;
}

void UnionFind::PrintContent() {
    cout << "Contents of " << this->name; 
    cout << " --- TPL = " << TotalPathLength(); 
    cout << ", total n_children = "<< TotalNumberOfChildren();
    cout << endl;
    int n = V.size();

    cout << "V[i]---->";
    for (int i = 0; i < n; ++i) {
        if(V[i] >= 0) cout << " ";
        cout << V[i] << " ";
    }
    cout << endl;

    cout << "PL(i)--->";
    for (int i = 0; i < n; ++i) {
        cout <<" "<< PathLength(i) << " ";
    }
    cout << endl;

    cout << "Find(i)->";
    for (int i = 0; i < n; ++i) {
        cout << " "<< Find(i) << " ";
    }
    cout << endl << endl;
}

