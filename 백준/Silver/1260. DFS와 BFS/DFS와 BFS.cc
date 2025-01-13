#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int main(){
    int n,m,v;
    cin >> n >> m  >> v;
    vector<vector<int>> g(n+1, vector<int> (n+1, 0)); 
    for (int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        g[a][b] |= 1;
        g[b][a] |= 1;
    }

    queue<int> q;
    stack<int> s;
    vector<int> visit(n+1);

    s.push(v);
    while (!s.empty()){
        int vert = s.top();
        s.pop();
        if (visit[vert])
            continue;
        cout << vert << " ";
        visit[vert] = 1;
        vector<int> edges = g[vert];
        for (int i=n; i>=1; i--){
            if (!visit[i] && edges[i])
                s.push(i);
        }
    }
    cout << endl;

    visit = vector<int>(n+1);
    q.push(v);
    while (!q.empty()){
        int vert = q.front();
        q.pop();
        if (visit[vert])
            continue;
        cout << vert << " ";
        visit[vert] = 1;
        vector<int> edges = g[vert];
        for (int i=1; i<=n; i++){
            if (!visit[i] && edges[i])
                q.push(i);
        }
    }
}