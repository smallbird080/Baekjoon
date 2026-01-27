#include <iostream>
#include <vector>
#include <array>

#define IO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

int dp[16][16][3]; // hor/vert/diag
int graph[16][16]; // (y, x)

int main() {
    IO;
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> graph[i][j];
            dp[i][j][0] = 0;
            dp[i][j][1] = 0;
            dp[i][j][2] = 0;
        }
    }
    dp[0][1][0] = 1;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (graph[i][j] == 1)
                continue;
            
            // arrive horizontally
            if (j-1 >= 0)
                dp[i][j][0] += (dp[i][j-1][0]+dp[i][j-1][2]);
            // arrive vertically
            if (i-1 >= 0)
                dp[i][j][1] += (dp[i-1][j][1]+dp[i-1][j][2]);
            // arrive diagonally
            if (i-1 >= 0 && j-1 >= 0 && !graph[i-1][j] && !graph[i][j-1])
                dp[i][j][2] += (dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2]);
        }
    }
    cout << (dp[n-1][n-1][0] + dp[n-1][n-1][1] + dp[n-1][n-1][2]);

}
