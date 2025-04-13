#include <iostream>
#include <vector>

using namespace std;

#define IO ios::sync_with_stdio(false);cin.tie(NULL)

int main() {
    IO;
    int n,s;
    cin >> n >> s;
    vector<long long> sum(n+1,0);
    int start = 0, end = 0, minLength = n+1;
    for (int i = 1; i <= n; i++) {
        end = i;
        int a;
        cin >> a;
        sum[i] = sum[i-1] + a;
        while (sum[end] - sum[start] >= s) {
            minLength = min(minLength, end - start);
            start++;
        }
    }
    if (minLength == n+1) {
        cout << 0;
    } 
    else {
        cout << minLength;
    }
}
