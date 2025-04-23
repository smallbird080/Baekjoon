#include <iostream>
#include <vector>
#include <algorithm>

#define IO ios::sync_with_stdio(false);cin.tie(NULL)

using namespace std;


int main() {
    IO;
    int n,m;
    cin >> n >> m;
    vector<vector<int> > dp(m+1,vector<int>(n+1,0));
    vector<pair<int,int> > item(m+1); // (w,v)
    for (int i=1; i<=m; i++)
        cin >> item[i].first >> item[i].second;
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            if (item[i].first > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-item[i].first]+item[i].second);
            }
        }
    }
    cout << dp[m][n];
}