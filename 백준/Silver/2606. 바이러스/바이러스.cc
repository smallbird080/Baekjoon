#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,m,from,to;
    cin >> n >> m;
    vector<vector<int>> edges(n);
    vector<bool> visited(n,false);
    while(m--){
        cin >> from >> to;
        edges[from-1].push_back(to-1);
        edges[to-1].push_back(from-1);
    }
    queue<int> q;
    q.push(0);
    visited[0] = true;
    int cnt=0;
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for (int v : edges[cur]){
            if (!visited[v]){
                visited[v] = true;
                q.push(v);
                cnt++;
            }
        }
    }

    cout << cnt;
}