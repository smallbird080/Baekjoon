#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 600000000

using namespace std;

int n,m;

struct Edge{
    int u,v,w;

    Edge(){}

    Edge(int _u, int _v, int _w) :u(_u), v(_v), w(_w) {}
};


int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    cin >> n >> m;
    vector<Edge> E;
    vector<long long> V(n+1);
    vector<bool> reached(n+1, false);
    reached[1] = true;

    V[1] = 0;
    for (int i=2; i<=n; i++)
        V[i] = INF;

    int u,v,w;
    while (m--){
        cin >> u >> v >> w;
        E.emplace_back(u,v,w);
    }

    for (int i=0; i<n-1; i++){
        for (Edge e : E){
            if (V[e.v] > V[e.u] + e.w){
                V[e.v] = V[e.u] + e.w;
                reached[e.v] = reached[e.u];
            }
        }
    }

    bool loop = false;
    for (Edge e : E){
        if (V[e.v] > V[e.u] + e.w && (reached[e.u])){
            loop = true;
            break;
        }
    }
    if (loop){
        cout << -1;
        return 0;
    }
    else{
        for (int i=2; i<=n; i++){
            int dist = reached[i] ? V[i] : -1;
            cout << dist << "\n";
        }
        return 0;
    }
}