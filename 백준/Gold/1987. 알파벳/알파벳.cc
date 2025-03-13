#include <iostream>
#include <vector>
#include <algorithm>

#define IO ios::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

bool visited[26];
int r,c;

void bt(const vector<vector<char>>& M, int row, int col, int cnt, int& maxD){
    int direction[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    maxD = max(maxD, cnt);
    for (int i=0; i<4; i++){
        int newR = row + direction[i][0];
        int newC = col + direction[i][1];
        if (newR < 0 || newC < 0 || newR >= r || newC >= c)
            continue;
        if (visited[M[newR][newC]-0x41])
            continue;
        visited[M[newR][newC]-0x41] = true;
        bt(M,newR,newC,cnt+1,maxD);
        visited[M[newR][newC]-0x41] = false;
    }
}

int main() {
    IO;
    cin >> r >> c;
    fill(visited,visited+26,false);
    vector<vector<char>> M(r,vector<char>(c));
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            cin >> M[i][j];
        }
    }
    int maxD = 0;
    visited[M[0][0]-0x41] = true;
    bt(M,0,0,1,maxD);
    cout << maxD;
}