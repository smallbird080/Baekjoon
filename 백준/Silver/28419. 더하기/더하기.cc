#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    int n,a;
    long odd=0,even=0;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a;
        if (i%2==0)
            even += a;
        else
            odd += a;
    }
    if (n==3 && even>odd)
        cout << -1;
    else
        cout << abs(even-odd);
}