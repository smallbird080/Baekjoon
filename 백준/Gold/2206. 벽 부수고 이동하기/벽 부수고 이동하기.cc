#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

#define INF 1000010

using namespace std;

int n,m;
pair<int,int> directions[4] = {{1,0},{0,1},{-1,0},{0,-1}};

struct Point{
    int r;
    int c;
    int dist;
    bool brk;

    Point(int row, int col, int d, bool broken){
        r = row;
        c = col;
        dist = d;
        brk = broken;
    }
};

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    cin >> n >> m;
    string wall;
    vector<vector<bool>> G(n,vector<bool>(m));
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    vector<vector<bool>> brkVisited(n,vector<bool>(m,false));
    for (int i=0; i<n; i++){
        cin >> wall;
        for (int j=0; j<m; j++){
            G[i][j] = wall[j] == '1';
        }
    }
    if (n == 1 && m == 1){
        cout << 1;
        return 0;
    }
    queue<Point> q;
    q.emplace(0,0,1,false);
    visited[0][0] = true;
    bool reached = false;
    int res = INF;
    while (!q.empty()){
        int row = q.front().r, col = q.front().c, dist = q.front().dist;
        bool broken = q.front().brk;
        q.pop();
        for (pair<int,int> p : directions){
            int tmpR = row + p.first;
            int tmpC = col + p.second;
            if (tmpR == n || tmpR == -1 || tmpC == m || tmpC == -1) 
                continue;
            if (row == n-1 && col == m-1){
                res = min(res,dist);
                reached = true;
                break;
            }
            if (visited[tmpR][tmpC])
                continue;
            if (broken){
                if (brkVisited[tmpR][tmpC])
                    continue;
                if (!G[tmpR][tmpC]){
                    q.emplace(tmpR,tmpC,dist+1,true);
                    brkVisited[tmpR][tmpC] = true;
                }
            }
            else {
                if (G[tmpR][tmpC]){
                    q.emplace(tmpR,tmpC,dist+1,true);
                    brkVisited[tmpR][tmpC] = true;
                }
                else{
                    q.emplace(tmpR,tmpC,dist+1,false);
                    visited[tmpR][tmpC] = true;
                }
            }
        }
    }
    if (!reached){
        cout << -1;
    } else {
        cout << res;
    }
    return 0;
}