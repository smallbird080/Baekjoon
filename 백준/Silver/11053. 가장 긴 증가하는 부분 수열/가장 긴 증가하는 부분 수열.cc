#include <iostream>
#include <vector>
#include <algorithm>

#define IO ios::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

int main() {
    IO;
    int n;
    cin >> n;
    vector<int> A(n+1,0);
    vector<int> D(n+1,0);
    for (int i=1; i<=n; i++)
        cin >> A[i];
    for (int i=1; i<=n; i++){
        for (int j=0; j<i; j++){
            if (A[j] < A[i]){
                D[i] = max(D[i],D[j]);
            }
        }
        D[i]++;
    }
    cout << *max_element(D.begin(), D.end());
}