#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct DisjSet{
    int arr[10001];

    DisjSet(int n){
        for (int i=0; i<n; i++)
            arr[i] = -1;
    }

    int find(int x){
        if (arr[x] < 0)
            return x;
        arr[x] = find(arr[x]);
        return arr[x];
    }

    bool uni(int x, int y){
        if (x==y)
            return false;
        if (arr[x] > arr[y])
            arr[x] = y;
        else{
            if (arr[x] == arr[y])
                (arr[x])--;
            arr[y] = x;
        }
        return true;
    }
};

struct Edge{
    short u,v;
    int w;
    
    bool operator<(const Edge& other){
        return this->w < other.w;
    }
};

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    int v,e;
    cin >> v >> e;
    DisjSet verts(v);
    Edge E[100001];
    for (int i=0; i<e; i++){
        cin >> E[i].u >> E[i].v >> E[i].w;
    }
    sort(E ,E+e);
    int totalWeight = 0;
    for (int i=0; i<e; i++){
        if (verts.uni(verts.find(E[i].u),verts.find(E[i].v)))
            totalWeight += E[i].w;
    }
    cout << totalWeight;
}