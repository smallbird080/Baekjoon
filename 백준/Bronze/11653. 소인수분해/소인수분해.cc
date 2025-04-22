#include <iostream>
#include <vector>

using namespace std;

#define IO ios::sync_with_stdio(false);cin.tie(NULL)

int main() {
    IO;
    int n;
    cin >> n;
    int num = n;
    for (int i=2; i<=n; i++){
        if (num == 1)
            break;
        while (num % i == 0){
            num /= i;
            cout << i << "\n";
        }
    }
}
