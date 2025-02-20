#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isTip(const vector<vector<pair<int,bool>>>& m, int row, int col){
    bool result = true;
    int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    for (auto& dir : directions) {
        int newRow = row + dir[0];
        int newCol = col + dir[1];
        if (m[newRow][newCol].first > m[row][col].first) {
            result = false;
            break;
        }
    }
    return result;
}

bool bfs(vector<vector<pair<int,bool>>>& m, int row, int col){
    int topH = m[row][col].first;
    m[row][col].second = true;
    queue<pair<int,int>> q;
    q.emplace(row,col);
    while (!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        for (auto& dir : directions) {
            int newRow = r + dir[0];
            int newCol = c + dir[1];
            if (!m[newRow][newCol].second && m[newRow][newCol].first == m[r][c].first){
                q.emplace(newRow, newCol);
                m[newRow][newCol].second = true;
            }
            else if (m[newRow][newCol].first > topH)
                return false;
            
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,bool>>> farm(n+2,vector<pair<int,bool>>(m+2,{-1,false}));
    for (int i=0; i<=n+1; i++){
        farm[i][0].second = true;
        farm[i][m+1].second = true;
    }
    for (int i=0; i<=m+1; i++){
        farm[0][i].second = true;
        farm[n+1][i].second = true;
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++)
            cin >> farm[i][j].first;
    }

    int result = 0;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (!farm[i][j].second && isTip(farm,i,j) && bfs(farm,i,j)){
                result++;
            }
        }
    }
    cout << result;
}