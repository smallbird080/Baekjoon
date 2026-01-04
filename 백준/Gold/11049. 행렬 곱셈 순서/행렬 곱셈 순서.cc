#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define IO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;


int main(){
    IO;
    int n;
    int dp[500][500];
    int mat[501];
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> mat[i] >> mat[i+1];
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++)
            dp[i][j] = __INT_MAX__;
    }
    if (n==1){
        cout << 0;
        return 0;
    }

    for (int i=0; i<n; i++)
        dp[i][i] = 0;
    
    for (int len=1; len<n; len++){
        for (int j=0; len+j<n; j++){
            dp[j][len+j] = __INT_MAX__;
            for (int k=j; k<len+j; k++){
                dp[j][len+j] = min(dp[j][len+j], dp[j][k] + dp[k+1][len+j] + mat[j]*mat[k+1]*mat[len+j+1]);
            }
        }
    }

    cout << dp[0][n-1];

    return 0;
}