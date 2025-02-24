#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 1000000000

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    int a,b;
    cin >> a >> b;
    queue<pair<long long,int>> q;
    vector<bool> visited(INF+1,false);
    q.emplace(a,1);
    visited[a] = true;
    while (!q.empty()){
        long long cur = q.front().first;
        int d = q.front().second;
        if (cur == b){
            cout << d;
            return 0;
        }
        q.pop();
        if (cur*2 <= INF && cur*2 < 2*b+1 && !visited[cur*2]){
            q.emplace(cur*2, d+1);
            visited[cur*2] = true;
        }
        if (cur*10+1 <= INF && cur*10+1 < 2*b+1 && !visited[cur*10+1]){
            q.emplace(cur*10+1,d+1);
            visited[cur*10+1] = true;
        }
    }
    cout << -1;
    return 0;
}