#include <iostream>
#include <vector>

#define IO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

int main() {
    IO;
    int n, k;
    cin >> n >> k;
    vector<int> a(n,0);
    for (int i=0; i<n; i++){
        int coin;
        cin >> coin;
        a[i] = coin;
    }
    int cnt=0;
    for (int i=n-1; i>=0; i--){
        int div = k / a[i];
        if (div == 0)
            continue;
        else{
            cnt += div;
            k %= a[i];
        }
    }
    cout << cnt;
    return 0;
}
