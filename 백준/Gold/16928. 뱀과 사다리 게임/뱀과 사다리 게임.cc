#include <iostream>
#include <vector>
#include <queue>

#define IO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

int board[101][6];
int visitedRound[101];

int main() {
    IO;
    for (int i=1; i<=100; i++){
        for (int j=0; j<6; j++)
            board[i][j] = i+j+1;
        visitedRound[i] = 100000;
    }
    int n,m,s,e;
    cin >> n >> m;
    for (int i=0; i<n+m; i++){
        cin >> s >> e;
        board[s][0] = -1;
        board[s][1] = e;
    }
    queue<pair<int,int>> q; // point, rolls
    q.emplace(1,0);
    int result = 100000;
    while (!q.empty()){
        int cur = q.front().first;
        int roll = q.front().second;
        q.pop();
        if (cur > 100)
            continue;
        if (cur == 100){
            result = min(result, roll);
        }
        if (board[cur][0] == -1){
            q.emplace(board[cur][1], roll);
            visitedRound[board[cur][1]] = roll;
            continue;
        }
        for (int i=0; i<6; i++){
            int dest = board[cur][i];
            if (visitedRound[dest] > roll+1){
                q.emplace(dest, roll+1);
                visitedRound[dest] = roll+1;
            }
        }
    }
    cout << result;
}
