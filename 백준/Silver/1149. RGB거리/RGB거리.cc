#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin >> n;
    int current[3] = {0,0,0};
    vector<int> BR(n+1,0);
    vector<int> GR(n+1,0);
    vector<int> BG(n+1,0);
    vector<int> RG(n+1,0);
    vector<int> RB(n+1,0);
    vector<int> GB(n+1,0);
    for (int i=1; i<=n; i++){
        cin >> current[0] >> current[1] >> current[2];
        BR[i] = min(RB[i-1]+current[0], GB[i-1]+current[0]);
        GR[i] = min(RG[i-1]+current[0], BG[i-1]+current[0]);
        BG[i] = min(RB[i-1]+current[1], GB[i-1]+current[1]);
        RG[i] = min(BR[i-1]+current[1], GR[i-1]+current[1]);
        RB[i] = min(BR[i-1]+current[2], GR[i-1]+current[2]);
        GB[i] = min(RG[i-1]+current[2], BG[i-1]+current[2]);
    }

    int result = min({BR[n], GR[n], BG[n], RG[n], RB[n], GB[n]});
    cout << result;
}