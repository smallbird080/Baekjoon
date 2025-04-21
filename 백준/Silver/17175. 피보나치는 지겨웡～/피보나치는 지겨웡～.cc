#include <iostream>
#include <vector>

using namespace std;

#define IO ios::sync_with_stdio(false);cin.tie(NULL)
#define MOD 1000000007

int main() {
    IO;
    int n;
    cin >> n;
    int dp[51];
    dp[0] = 1;
    dp[1] = 1;
    for (int i=2; i<=n; i++){
        dp[i] = (dp[i-1] + dp[i-2] + 1) % MOD;
    }
    cout << dp[n];
}
