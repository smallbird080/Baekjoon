#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define IO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

int nums[2000];
bool dp[2001][2001];

int main(){
    IO;
    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> nums[i];
    for (int i=0; i<n; i++){
        dp[0][i] = true;
        dp[1][i] = true;
    }
    
    for (int len=2; len<=n; len++){
        for (int i=0; i+len <= n; i++){
            int end = i+len-1;
            if (len > 2)
                dp[len][i] = (dp[len-2][i+1] && nums[i] == nums[end]);
            else
                dp[len][i] = nums[i] == nums[end];
        }
    }
    int m;
    cin >> m;
    for (int i=0; i<m; i++){
        int s,e;
        cin >> s >> e;
        cout << dp[e-s+1][s-1]<< '\n';
    }
}