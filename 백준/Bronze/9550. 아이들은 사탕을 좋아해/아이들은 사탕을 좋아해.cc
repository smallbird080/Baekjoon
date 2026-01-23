#include <iostream>
#include <vector>
#include <array>

#define IO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    int children = 0;

    for (int i = 0; i < n; ++i) {
        int candy;
        cin >> candy; 
        children += (candy / k);
    }

    cout << children << "\n";
}

int main() {
    IO;
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}
