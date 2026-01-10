#include <iostream>
#include <vector>
#include <algorithm>

#define IO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

int main() {
    IO;
    int n;
    cin >> n;
    vector<int> A(n+2,0);
    vector<int> inc(n+2,0);
    vector<int> dec(n+2,0);
    for (int i=1; i<=n; i++)
        cin >> A[i];
    
    for (int i=1; i<=n; i++){
        for (int j=0; j<i; j++){
            if (A[i] > A[j])
                inc[i] = max(inc[i], inc[j]);
        }
        inc[i]++;
    }

    for (int i=n; i>=1; i--){
        for (int j=n+1; j>i; j--){
            if (A[i] > A[j])
                dec[i] = max(dec[i], dec[j]);
        }
        dec[i]++;
    }
    
    int result = 0;
    for (int i=1; i<=n; i++){
        result = max(result, inc[i]+dec[i]-1);
    }
    cout << result;
}
