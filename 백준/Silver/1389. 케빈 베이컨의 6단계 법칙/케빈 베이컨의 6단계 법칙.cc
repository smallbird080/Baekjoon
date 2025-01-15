#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void calculateKV(vector<vector<int>>& g, vector<int>& d, int n);

int main(){
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> reln(n,vector<int>(n,0));
    vector<int> kv(n,0);
    for (int i=0; i<m; i++){
        cin >> a >> b;
        reln[a-1][b-1] = 1;
        reln[b-1][a-1] = 1;
    }

    calculateKV(reln,kv,n);
}

void calculateKV(vector<vector<int>>& g, vector<int>& d, int n){
    int min = 9999;
    int minIdx = 0;
    vector<int> visited;
    vector<int> dist;
    for (int idx=0; idx<n; idx++){
        visited = vector<int>(n,0);
        dist = vector<int>(n,0);
        queue<int> q;
        q.push(idx);
        visited[idx] = 1;
        while (!q.empty()){
            int cur = q.front();
            q.pop();
            for (int u=0; u<n; u++){
                if (g[cur][u] && !visited[u]){
                    q.push(u);
                    visited[u] = 1;
                    dist[u] = dist[cur] + 1;
                }
            }
        }
        int totalKV = 0;
        for (int kv : dist)
            totalKV += kv;
        if (min > totalKV){
            min = totalKV;
            minIdx = idx;
        }
    }
    cout << minIdx + 1;
}
