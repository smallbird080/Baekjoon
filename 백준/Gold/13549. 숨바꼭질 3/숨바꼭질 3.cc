#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    vector<bool> visited(100001,false);
    queue<pair<int,int>> pos;
    pos.push({n,0});
    visited[n] = true;
    while (!pos.empty()){
        int idx = pos.front().first;
        int dist = pos.front().second;
        pos.pop();
        if (idx==k){
            cout << dist;
            break;
        }
        if (idx*2 <= 100000 && !visited[idx*2]){
            visited[idx*2] = true;
            pos.push({idx*2,dist});
        }

        if (idx > 0 && !visited[idx-1]){
            visited[idx-1] = true;
            pos.push({idx-1,dist+1});
        }
        if (idx < 100000 && !visited[idx+1]){
            visited[idx+1] = true;
            pos.push({idx+1,dist+1});

        }
    }
}