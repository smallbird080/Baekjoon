#include <iostream>
#include <vector>
#include <algorithm>

#define IO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin >> n;
    int current[3] = {0,0,0};
    vector<int> RR(n+1,0); 
    vector<int> GR(n+1,0);
    vector<int> BR(n+1,0);

    vector<int> RG(n+1,0);
    vector<int> GG(n+1,0);
    vector<int> BG(n+1,0);

    vector<int> RB(n+1,0);
    vector<int> GB(n+1,0);
    vector<int> BB(n+1,0);
    cin >> current[0] >> current[1] >> current[2];
    RR[1] = current[0];
    GR[1] = current[1];
    BR[1] = current[2];
    RG[1] = current[0];
    GG[1] = current[1];
    BG[1] = current[2];
    RB[1] = current[0];
    GB[1] = current[1];
    BB[1] = current[2];
    for (int i=2; i<=n; i++){
        cin >> current[0] >> current[1] >> current[2];
        RR[i] = min(RG[i-1] + current[0], RB[i-1] + current[0]);
        GR[i] = min(GB[i-1] + current[0], GG[i-1] + current[0]);
        BR[i] = min(BG[i-1] + current[0], BB[i-1] + current[0]);
        RG[i] = min(RB[i-1] + current[1], RR[i-1] + current[1]);
        GG[i] = min(GB[i-1] + current[1], GR[i-1] + current[1]);
        BG[i] = min(BR[i-1] + current[1], BB[i-1] + current[1]);
        RB[i] = min(RG[i-1] + current[2], RR[i-1] + current[2]);
        GB[i] = min(GR[i-1] + current[2], GG[i-1] + current[2]);
        BB[i] = min(BR[i-1] + current[2], BG[i-1] + current[2]);
        if (i==2){
            RR[i] = 500000;
            GG[i] = 500000;
            BB[i] = 500000;
        }
    }
    cout << min({RG[n],RB[n],BG[n],BR[n],GB[n],GR[n]});
}