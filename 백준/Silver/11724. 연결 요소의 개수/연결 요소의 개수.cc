#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Graph;

int dfs(Graph& g, int n);

void visit(Graph& g, int v, vector<bool>& visited);

int main(){
    int n, m;
    cin >> n >> m;
    Graph g(n);
    for (int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;
        g[x-1].push_back(y-1);
        g[y-1].push_back(x-1);
    }
    cout << dfs(g, n);
}

int dfs(Graph& g, int n){
    vector<bool> visited(n,false);
    int cc = 0;
    for (int i=0; i<n; i++){
        if (!visited[i]){
            cc++;
            visit(g,i,visited);
        }
    }
    return cc;
}

void visit(Graph& g, int v, vector<bool>& visited){
    visited[v] = true;
    for (int u : g[v]){
        if (!visited[u])
            visit(g,u,visited);
    }
}
