#include <iostream>
#include <array>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,goal;
    array<int,11> dp = {0};
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i=4; i<12; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    cin >> n;
    while(n--){
        cin >> goal;
        cout << dp[goal] << "\n";
    }
}