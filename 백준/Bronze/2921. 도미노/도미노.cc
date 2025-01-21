#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, result=0;;
    cin >> n;
    for (int i=0; i<=n; i++){
        for (int j=i; j<=n; j++){
            result = result + i + j;
        }
    }
    cout << result;
}