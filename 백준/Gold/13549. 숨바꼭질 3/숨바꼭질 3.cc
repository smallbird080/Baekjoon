#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    vector<bool> visited(100001,false);
    deque<pair<int,int>> pos;
    pos.push_front({n,0});
    visited[n] = true;
    while (!pos.empty()){
        int idx = pos.front().first;
        int dist = pos.front().second;
        pos.pop_front();
        if (idx==k){
            cout << dist;
            break;
        }
        if (idx*2 <= 100000 && !visited[idx*2]){
            visited[idx*2] = true;
            pos.push_front({idx*2,dist});
        }

        if (idx > 0 && !visited[idx-1]){
            visited[idx-1] = true;
            pos.push_back({idx-1,dist+1});
        }
        if (idx < 100000 && !visited[idx+1]){
            visited[idx+1] = true;
            pos.push_back({idx+1,dist+1});

        }
    }
}