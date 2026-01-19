#include <iostream>
#include <vector>
#include <queue>

#define IO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main() {
    IO;
    int n,m;
    cin >> n >> m;
    vector<vector<int>> map(n,vector<int>(m,0));
    for (int i=0; i<n; i++){
        string s;
        cin >> s;
        for (int j=0; j<m; j++){
            map[i][j] = s[j]-'0';
        }
    }

    queue<pair<int,int>> q;
    q.emplace(0,0);
    map[0][0] = -1;
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == n-1 && y == m-1){
            cout << -map[x][y];
            return 0;
        }
        for (int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == 1){
                q.emplace(nx,ny);
                map[nx][ny] = map[x][y] - 1;
            }
        }
    }
}
