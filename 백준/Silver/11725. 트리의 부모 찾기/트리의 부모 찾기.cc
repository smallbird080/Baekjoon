#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    int n,u,v;
    cin >> n;
    vector<vector<int>> g(n+1);
    vector<pair<int,bool>> vertices(n+1,{0,false});
    for (int i=1; i<=n; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for (int vertex : g[cur]){
            if (!vertices[vertex].second){
                vertices[vertex].first = cur;
                vertices[vertex].second = true;
                q.push(vertex);
            }
        }
    }
    for (int i=2; i<=n; i++){
        cout << vertices[i].first << "\n";
    }
}