#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int result = 0;

vector<pair<char,char>> update(vector<pair<char,char>> placed, char row, char idx){
    placed.push_back({row,idx});
    return placed;
}

void solve(vector<pair<char,char>> placed, int row){
    vector<bool> ok(n,true);
    for (pair<char,char> pos : placed){
        char history = pos.second;
        ok[history] = false;
        char dist = row - pos.first;
        if (history-dist >= 0)
            ok[history-dist] = false;
        if (history+dist < n)
            ok[history+dist] = false;
    }
    for (int i=0; i<n; i++){
        if (ok[i]){
            if (row == n-1){
                result++;
                continue;
            }
            solve(update(placed,row,i), row+1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    cin >> n;
    vector<pair<char,char>> placed;
    solve(placed,0);
    cout << result;
}