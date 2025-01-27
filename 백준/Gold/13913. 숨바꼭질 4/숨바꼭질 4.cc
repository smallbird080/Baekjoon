#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int k;

void print(const vector<pair<bool,int>>& visited, int index){
    if (index == n){
        cout << n << " ";
        return;
    }
    print(visited,visited[index].second);
    cout << index << " ";
}

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    int idx;
    cin >> n >> k;
    vector<pair<bool,int>> visited(100001,{false,-1});
    queue<pair<int,int>> pos;
    pos.push({n,0});
    visited[n].first = true;
    visited[n].second = n;

    while (!pos.empty()){
        idx = pos.front().first;
        int dist = pos.front().second;
        pos.pop();
        if (idx==k){
            cout << dist << "\n";
            break;
        }
        if (idx*2 <= 100000 && !visited[idx*2].first){
            visited[idx*2].first = true;
            visited[idx*2].second = idx;
            pos.push({idx*2,dist+1});
        }

        if (idx > 0 && !visited[idx-1].first){
            visited[idx-1].first = true;
            visited[idx-1].second = idx;
            pos.push({idx-1,dist+1});
        }
        if (idx < 100000 && !visited[idx+1].first){
            visited[idx+1].first = true;
            visited[idx+1].second = idx;
            pos.push({idx+1,dist+1});

        }
    }
    print(visited,idx);
}