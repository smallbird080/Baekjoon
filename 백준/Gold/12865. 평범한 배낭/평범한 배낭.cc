#include <iostream>
#include <vector>
#include <set>

#define IO ios::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

int main() {
    IO;
    int n,k;
    cin >> n >> k;
    vector<vector<int> > dp(n+1,vector<int>(k+1,0));
    vector<pair<int,int> > item(n+1); // (w,v)
    for (int i=1; i<=n; i++)
        cin >> item[i].first >> item[i].second;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=k; j++){
            if (item[i].first > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-item[i].first]+item[i].second);
            }
        }
    }
    cout << dp[n][k];
}