#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    vector<int> pos(100001,-1);
    int n,k,cost=100100,ways=0;
    cin >> n >> k;
    queue<pair<int,int>> q; // (idx, cost)
    q.emplace(n,0);
    pos[n] = 0;
    while (!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        int idx = cur.first;
        int depth = cur.second;
        if (idx == k){
            cost = depth;
            ways++;
            continue;
        }
        if (idx+1 <= 100000 && (pos[idx+1] == -1 || pos[idx+1] == depth)){
            pos[idx+1] = depth;
            q.emplace(idx+1,depth+1);
        }
        if (idx-1 >= 0 && (pos[idx-1] == -1 || pos[idx-1] == depth)){
            pos[idx-1] = depth;
            q.emplace(idx-1,depth+1);
        }
        if (idx*2 <= 100000 && (pos[idx*2] == -1 || pos[idx*2] == depth)){
            pos[idx*2] = depth;
            q.emplace(idx*2,depth+1);
        }
    }
    cout << cost << "\n" << ways;
}