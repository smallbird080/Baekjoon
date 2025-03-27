#include <iostream>
#include <vector>
#include <algorithm>

#define IO ios::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

struct DisjSet{
    int arr[100000];

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
    int u;
    int v;
    int w;

    Edge(int _u, int _v, int _w):u(_u),v(_v),w(_w){}
    
    bool operator<(const Edge &other) const {
        return this->w < other.w;
    }
};


int main() {
    IO;
    int n;
    cin >> n;
    DisjSet ds(n);
    vector<Edge> E;
    vector<pair<int,int>> X(n),Y(n),Z(n);
    for (int i=0; i<n; i++){
        cin >> X[i].first >> Y[i].first >> Z[i].first;
        X[i].second = i;
        Y[i].second = i;
        Z[i].second = i;
    }
    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());
    sort(Z.begin(),Z.end());
    for (int i=1; i<n; i++){
        E.emplace_back(X[i-1].second, X[i].second, abs(X[i].first - X[i-1].first));
        E.emplace_back(Y[i-1].second, Y[i].second, abs(Y[i].first - Y[i-1].first));
        E.emplace_back(Z[i-1].second, Z[i].second, abs(Z[i].first - Z[i-1].first));
    }
    sort(E.begin(),E.end());
    long long cost = 0;
    for (Edge edge : E){
        if (ds.uni(ds.find(edge.u),ds.find(edge.v))){
            cost += edge.w;
        }
    }
    cout << cost;
}