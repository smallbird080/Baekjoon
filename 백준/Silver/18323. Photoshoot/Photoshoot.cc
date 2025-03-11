#include <iostream>
#include <algorithm>
#include <vector>

#define IO ios::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

int main() {
    IO;
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i=1; i<n; i++)
        cin >> b[i];
    vector<int> a(n);
    vector<bool> check(n+1);
    for (int i=1; i<=n; i++){
        int len = 1;
        fill(check.begin(), check.end(), false);
        check[i] = true;
        b[0] = i;
        a[0] = i;
        for (int j=1; j<n; j++){
            int num = b[j] - a[j-1];
            if (num <= 0 || num > n || check[num])
                break;
            a[j] = num;
            check[num] = true;
            len++;
        }
        if (len==n)
            break;
    }
    for (int i=0; i<n; i++)
        cout << a[i] << " ";
}