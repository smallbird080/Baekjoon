#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[7];
    for (int i = 0; i < 7; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + 7);
    int A = arr[0];
    int B = arr[1];
    int S = arr[6];
    int C = S - A - B;
    
    cout << A << " " << B << " " << C;
    return 0;
}
