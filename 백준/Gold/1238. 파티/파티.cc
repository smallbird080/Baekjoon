#include <iostream>
#include <vector>
#include <queue>

#define INF 100000000

using namespace std;

int n,m,x;

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    cin >> n >> m >> x;
    vector<vector<pair<int,int>>> g(n); // (idx,weight)
    vector<vector<int>> distMem(n,vector<int>(n,INF));
    for (int i=0; i<m; i++){
        int f,t,w;
        cin >> f >> t >> w;
        g[f-1].emplace_back(t-1,w);
    }
    for (int i=0; i<n; i++){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> q; // (dist, idx)
        q.emplace(0,i);
        distMem[i][i] = 0;
        vector<bool> v(n,false);
        while (!q.empty()){
            int dist = q.top().first;
            int idx = q.top().second;
            q.pop();
            if (v[idx])
                continue;
            v[idx] = true;
            for (pair<int,int> e : g[idx]){
                if (distMem[i][e.first] > dist + e.second){
                    distMem[i][e.first] = dist + e.second;
                    q.emplace(dist+e.second, e.first);
                }
            }
        }
    }
    int result = 0;
    for (int i=0; i<n; i++){
        int dist = distMem[i][x-1] + distMem[x-1][i];
        result = result < dist ? dist : result; 
    }
    cout << result;
}