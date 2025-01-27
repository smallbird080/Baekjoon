#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 2000000
using namespace std;

typedef vector<vector<pair<int,int>>> Graph;

struct cmp{
    bool operator()(pair<int,int> p1, pair<int,int>p2){
        return p1.second > p2.second;
    }
};

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    int v,e,k,u,w;
    cin >> v >> e >> k;
    Graph g(v); // (end, cost)
    priority_queue<pair<int,int>,vector<pair<int,int>>, cmp> q; // (idx, dist)
    vector<pair<int,bool>> verts(v,{INF,false}); // (dist, visited)
    q.emplace(k-1,0);
    verts[k-1] = {0,false};
    while (e--){
        cin >> u >> v >> w;
        g[u-1].push_back({v-1,w});
    }

    while (!q.empty()){
        pair<int,int> cur = q.top();
        q.pop();
        if (verts[cur.first].second){
            continue;
        }
        verts[cur.first].second = true;
        for (pair<int,int> end : g[cur.first]){
            if (verts[end.first].first > cur.second + end.second){
                verts[end.first].first = cur.second + end.second;
                q.emplace(end.first,verts[end.first].first);
            }
        }
    }
    for (pair<int,int> vertex : verts){
        if (vertex.first >= INF)
            cout << "INF\n";
        else
            cout << vertex.first << "\n";
    }
}