#include <iostream>
#include <queue>
#include <vector>
#define INF 999*100000+1
using namespace std;

struct Vertex{
    bool visited;
    int dist;
    
    Vertex(bool _visited=false, int _dist=INF): visited(visited), dist(_dist) {}
};

struct cmp {
    bool operator()(const pair<int,int> p1, const pair<int,int> p2){
        return p1.second > p2.second;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,s,e,w,init,goal;
    cin >> n >> m;
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> q; // (idx, cost)
    vector<vector<int>> edges(n,vector<int>(n,INF));
    Vertex verts[n];
    while (m--){
        cin >> s >> e >> w;
        edges[s-1][e-1] = min(edges[s-1][e-1],w);
    }
    cin >> init >> goal;
    

    for (int i=0; i<n; i++){
        verts[i].visited = false;
        if (i == init-1){
            verts[init-1].dist = 0;
            q.push({i,0});
        }
        else{
            verts[i].dist = INF;
            q.push({i,INF});
        }
    }

    while (true){
        pair<int,int> cur = q.top();
        q.pop();
        if (verts[cur.first].visited)
            continue;
        verts[cur.first].visited = true;
        if (cur.first == goal-1){
            cout << cur.second;
            break;;
        }
        for (int i=0; i<n; i++){
            if (!verts[i].visited && verts[i].dist > verts[cur.first].dist + edges[cur.first][i]){
                verts[i].dist = verts[cur.first].dist + edges[cur.first][i];
                q.push({i,verts[i].dist});
            }
        }
    }
}