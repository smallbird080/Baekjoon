#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define IO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;
typedef vector<vector<pair<char,bool>>> MAP;

int main(){
    IO;
    int n, m, x, y;
    cin >> n >> m;
    MAP map(n, vector<pair<char,bool>>(m,{'X',false}));
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> map[i][j].first;
            if (map[i][j].first == 'I'){
                x = j;
                y = i;
                map[i][j].second = false;
            }
        }
    }
    int cnt = 0;
    queue<pair<int,int>> q;
    q.emplace(x,y);
    while (!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();    
        if (map[y][x].first == 'P')
            cnt++;

        if (x > 0) {
            if (!map[y][x-1].second && map[y][x-1].first != 'X'){
                q.emplace(x-1,y);
                map[y][x-1].second = true;
            }
        }
        if (x < m-1) {
            if (!map[y][x+1].second && map[y][x+1].first != 'X'){
                q.emplace(x+1,y);
                map[y][x+1].second = true;
            }
        }
        if (y > 0) {
            if (!map[y-1][x].second && map[y-1][x].first != 'X'){
                q.emplace(x,y-1);
                map[y-1][x].second = true;
            }
        }
        if (y < n-1) {
            if (!map[y+1][x].second && map[y+1][x].first != 'X'){
                q.emplace(x,y+1);
                map[y+1][x].second = true;
            }
        }
    }

    if (cnt)
        cout << cnt;
    else
        cout << "TT";
}