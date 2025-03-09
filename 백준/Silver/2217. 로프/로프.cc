#include <iostream>
#include <algorithm>
#include <vector>

#define IO ios::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

int main() {
    IO;
    int n;
    cin >> n;
    vector<int> rope(n);
    for (int i=0; i<n; i++){
        cin >> rope[i];
    }
    sort(rope.begin(),rope.end());
    int res = 0;
    for (int i=0; i<n; i++){
        res = max(res,rope[i]*(n-i));
    }
    cout << res;
}