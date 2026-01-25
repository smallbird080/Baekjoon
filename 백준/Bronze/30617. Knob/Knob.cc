#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define IO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

int main() {
    IO;
    int n,l1,r1,l2,r2;
    cin >> n;
    int result = 0;
    l1 = r1 = 0;
    for (int i=0; i<n; i++){
        cin >> l2 >> r2;
        if (l1 == l2 && l1 != 0)
            result++;
        if (r1 == r2 && r1 != 0)
            result++;
        if (l2 == r2 && l2 != 0)
            result++;
        l1 = l2;
        r1 = r2;
    }
    cout << result;
}
