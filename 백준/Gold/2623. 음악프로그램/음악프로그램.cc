#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#define IO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

int main() {
    IO;
    int n,m;
    cin >> n >> m;
    stack<int> s;
    vector<vector<int>> edge(n+1);
    vector<int> indeg(n+1,0);
    vector<int> answer;
    for (int i=0; i<m; i++){
        int x, prev, next;
        cin >> x >> prev;
        for (int j=1; j<x; j++){
            cin >> next;
            indeg[next]++;
            edge[prev].push_back(next);
            prev = next;
        }
    }

    for (int i=1; i<=n; i++){
        if (indeg[i] == 0)
            s.push(i);
    }

    while (!s.empty()){
        int cur = s.top();
        s.pop();
        answer.push_back(cur);
        for (int v : edge[cur]){
            indeg[v]--;
            if (indeg[v] == 0)
                s.push(v);
        }
    }

    if (answer.size() != (size_t)n){
        cout << 0;
        return 0;
    }
    else{
        for (int a : answer)
            cout << a << '\n';
    }
}
