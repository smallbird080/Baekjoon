#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    stack<int> s;
    vector<int> indeg(n+1,0);
    vector<vector<int>> G(n+1);
    for (int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        indeg[v]++;
    }
    for (int i=1; i<n+1; i++){
        if (indeg[i]==0)
            s.push(i);
    }
    while (!s.empty()){
        int top = s.top();
        s.pop();
        cout << top << " ";
        for (int i : G[top]){
            indeg[i]--;
            if (indeg[i] == 0)
                s.push(i);
        }
    }
    
}