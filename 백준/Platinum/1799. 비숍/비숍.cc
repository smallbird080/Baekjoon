#include <iostream>
#include <vector>
#include <algorithm>

#define Board vector<vector<int>>

using namespace std;

int n;

bool isSafe(const Board& b, int row, int col){
    for (int i=row, j=col; i>=0 && j>=0; i--, j--){
        if (b[i][j] == 2)
            return false;
    }
    for (int i=row, j=col; i>=0 && j<n; i--, j++){
        if (b[i][j] == 2)
            return false;
    }
    return true;
}

void solve(Board& b, int row, int col, int& maxB, int cnt){
    if (col >= n){
        row++;
        if(col%2 == 0) col = 1;
        else col = 0;
    }
    if (row >= n){
        maxB = max(maxB, cnt);
        return;
    }
    if (col < n && b[row][col] == 1 && isSafe(b,row,col)){
        b[row][col] = 2;
        solve(b,row,col+2,maxB,cnt+1);
        b[row][col] = 1;
    }
    solve(b,row,col+2,maxB,cnt);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    cin >> n;
    Board board(n,vector<int>(n));
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++)
            cin >> board[i][j];
    }
    int result1 = 0;
    int result2 = 0;
    solve(board,0,1,result1,0);
    solve(board,0,0,result2,0);
    cout << result1 + result2;
}