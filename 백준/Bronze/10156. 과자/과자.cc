#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    int a,b,c;
    cin >> a >> b >> c;
    int result = a*b-c;
    if (result > 0)
        cout << a*b-c;
    else
        cout << 0;
}