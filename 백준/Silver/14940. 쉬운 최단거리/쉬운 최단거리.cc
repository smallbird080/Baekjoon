#include <iostream>
#include <queue>

using namespace std;


int main(){
    bool visit[1002][1002];
    int n,m,a;
    cin>>n>>m;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            visit[i][j] = false;
        }
    }
    queue<pair<int,int>> q;
    int** map = new int*[n+2];
    for (int i=0; i<n+2; i++)
        map[i] = new int[m+2];
    for (int i=0; i<m+2; i++){
        map[0][i] = 0;
        map[n+1][i] = 0;
    }
    for (int i=1; i<n+1; i++){
        map[i][0] = 0;
        map[i][m+1] = 0;
        for (int j=1; j<m+1; j++){
            cin>>map[i][j];
            if(map[i][j] == 2){
                q.push({i,j});
            }
        }
    }

    int** dist = new int*[n];
    for (int i=0; i<n; i++)
        dist[i] = new int[m];
    for (int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dist[i][j] = -1;
        }
    }
    dist[q.front().first-1][q.front().second-1] = 0;

    for (int i=1; i<n+1; i++){
        for (int j=1; j<m+1; j++){
            if (map[i][j] == 0)
                dist[i-1][j-1] = 0;
        }
    }

    while (!q.empty()){
        pair<int,int> now = q.front();
        q.pop();
        map[now.first][now.second] = 0;
        if (visit[now.first-1][now.second] == false && map[now.first-1][now.second] != 0){
            visit[now.first-1][now.second] = true;
            q.push({now.first-1,now.second});
            dist[now.first-1-1][now.second-1] = dist[now.first-1][now.second-1] + 1;
        }
        if (visit[now.first+1][now.second] == false && map[now.first+1][now.second] != 0){
            visit[now.first+1][now.second] = true;
            q.push({now.first+1,now.second});
            dist[now.first-1+1][now.second-1] = dist[now.first-1][now.second-1] + 1;
        }
        if (visit[now.first][now.second-1] == false && map[now.first][now.second-1] != 0){
            visit[now.first][now.second-1] = true;
            q.push({now.first,now.second-1});
            dist[now.first-1][now.second-1-1] = dist[now.first-1][now.second-1] + 1;
        }
        if (visit[now.first][now.second+1] == false && map[now.first][now.second+1] != 0){
            visit[now.first][now.second+1] = true;
            q.push({now.first,now.second+1});
            dist[now.first-1][now.second-1+1] = dist[now.first-1][now.second-1] + 1;
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<'\n';
    }
    for (int i=0; i<n+1; i++)
        delete[] map[i];
    delete[] map;
    for (int i=0; i<n; i++)
        delete[] dist[i];
    delete[] dist;
}