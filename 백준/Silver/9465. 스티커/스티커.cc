#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    int t,n;
    cin >> t;
    while (t--){
        cin >> n;
        vector<int> up(n+1,0);
        vector<int> down(n+1,0);
        vector<int> none(n+1,0);
        vector<pair<int,int>> sticker(n);
        for (int i=0; i<n; i++)
            cin >> sticker[i].first;
        for (int i=0; i<n; i++)
            cin >> sticker[i].second;
        for (int i=1; i<=n; i++){
            up[i] = max(down[i-1],none[i-1]) + sticker[i-1].first;
            down[i] = max(up[i-1],none[i-1]) + sticker[i-1].second;
            none[i] = max(down[i-1],up[i-1]);
        }
        cout << max({up[n],down[n],none[n]}) << "\n";
    }
}