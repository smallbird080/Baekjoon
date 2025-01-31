#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 1000*100000

using namespace std;

struct cmp{
    bool operator()(pair<int,int> p1, pair<int,int>p2){
        return p1.second > p2.second;
    }
};


int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    int n,m,s,e,w;
    cin >> n >> m;
    vector<vector<int>> g(n,vector<int>(n,INF));
    vector<pair<int,int>> vertex(n,{INF,-1}); // (dist,pred)
    while (m--){
        cin >> s >> e >> w;
        g[s-1][e-1] = min(g[s-1][e-1],w);
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>, cmp> q; // (idx,dist);
    cin >> s >> e;
    vertex[s-1].first = 0;
    q.emplace(s-1,0);
    while (!q.empty()){
        int idx = q.top().first;
        int dist = q.top().second;
        if (idx == e-1){
            break;
        }
        q.pop();
        for (int i=0; i<n; i++){
            if (vertex[i].first > dist + g[idx][i]){
                vertex[i].first = dist + g[idx][i];
                vertex[i].second = idx;
                q.emplace(i,vertex[i].first);
            }
        }
    }

    vector<int> path;
    path.push_back(e-1);
    while(path.back()!=s-1){
        path.push_back(vertex[path.back()].second);
    }
    cout << vertex[e-1].first << "\n";
    cout << path.size() << "\n";
    while (!path.empty()){
        cout << path.back()+1 << " ";
        path.pop_back();
    }

}