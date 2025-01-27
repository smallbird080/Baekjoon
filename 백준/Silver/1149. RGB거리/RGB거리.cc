#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin >> n;
    int current[3] = {0,0,0};
    vector<int> R(n+1,0);
    vector<int> G(n+1,0);
    vector<int> B(n+1,0);
    for (int i=1; i<=n; i++){
        cin >> current[0] >> current[1] >> current[2];
        R[i] = min(G[i-1]+current[0],B[i-1]+current[0]);
        G[i] = min(R[i-1]+current[1],B[i-1]+current[1]);
        B[i] = min(R[i-1]+current[2],G[i-1]+current[2]);
    }
    cout << min({R[n],B[n],G[n]});
}