#include <iostream>
#include <vector>
#include <queue>

#define IO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

int dx[6] = {1, -1, 0, 0, 0, 0}; // m
int dy[6] = {0, 0, 1, -1, 0, 0}; // h
int dz[6] = {0, 0, 0, 0, 1, -1}; // n

struct pos{
    int x,y,z,day;
    pos(int _x, int _y, int _z, int _day):x(_x),y(_y),z(_z),day(_day){}
};

vector<vector<vector<int>>> tomato;
queue<pos> q;
int cntTomato;

int bfs(int n, int m, int h){
    int days = 0;
    while (!q.empty()){
        int x, y, z, day;
        x = q.front().x;
        y = q.front().y;
        z = q.front().z;
        day = q.front().day;
        days = max(days, day);
        cntTomato--;
        q.pop();

        for (int i=0; i<6; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if (nx >= 0 && nx < m && ny >=0 && ny < h && nz >=0 && nz < n && tomato[ny][nz][nx] == 0){
                tomato[ny][nz][nx] = 1;
                q.emplace(nx,ny,nz,day+1);
            }
        }
    }
    return days;
}

int main() {
    IO;
    int n, m, h;
    cin >> m >> n >> h;
    tomato = vector<vector<vector<int>>>(h,vector<vector<int>>(n,vector<int>(m,0))); // [y][z][x]

    cntTomato = n * m * h;
    for (int i=0; i<h; i++){
        for (int j=0; j<n; j++){
            for (int k=0; k<m; k++){
                int state;
                cin >> state;
                tomato[i][j][k] = state;
                if (state == 1)
                    q.emplace(k,i,j,0);
                else if (state == -1)
                    cntTomato--;
            }
        }
    }

    int days = bfs(n,m,h);
    if (cntTomato != 0)
        cout << -1;
    else
        cout << days;

}
