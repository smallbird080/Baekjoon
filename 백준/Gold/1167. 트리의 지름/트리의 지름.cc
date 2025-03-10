#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define IO ios::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

struct Node{
    vector<pair<int,int>> vertex;
    bool visited = false;
    int dist=0;

    void reset(){
        this->visited = false;
        this->dist = 0;
    }
};

pair<int,int> bfs(vector<Node>& tree, int root){
    int maxLen = 0;
    int maxVert = 0;
    queue<int> q;
    q.emplace(root);
    tree[root].visited = true;
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        int childLen = tree[cur].vertex.size();
        if (childLen==1 && cur != root){
            if (tree[cur].dist > maxLen){
                maxLen = tree[cur].dist;
                maxVert = cur;
            }
            continue;
        }
        for (int i=0; i<childLen; i++){
            int v = tree[cur].vertex[i].first;
            if (!tree[v].visited){
                q.push(v);
                tree[v].dist += tree[cur].dist + tree[cur].vertex[i].second;
                tree[v].visited = true;
            }
        }
    }
    return {maxVert,maxLen};
}

int main() {
    IO;
    int n;
    cin >> n;
    vector<Node> Tree(n+1);
    for (int i=0; i<n; i++){
        int u,v=0,w;
        cin >> u;
        while (true){
            cin >> v;
            if (v==-1)
                break;
            cin >> w;
            Tree[u].vertex.emplace_back(v,w);
        }
    }
    int far = bfs(Tree,1).first;
    for (int i=1; i<=n; i++){
        Tree[i].reset();
    }
    cout << bfs(Tree,far).second;
}