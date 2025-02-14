#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> tri(n,vector<int>(n,0));
    cin >> tri[0][0];
    for (int i=1; i<n; i++){
        for (int j=0; j<=i; j++){
            cin >> tri[i][j];
            if (j==0)
                tri[i][j] += tri[i-1][j];
            else
                tri[i][j] += max(tri[i-1][j],tri[i-1][j-1]);
        }
    }
    int result = tri[n-1][0];
    for (int val : tri[n-1])
        result = max(result, val);
    cout << result;
}