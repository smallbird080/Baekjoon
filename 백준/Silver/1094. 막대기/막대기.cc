#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

#define IO ios::sync_with_stdio(false);cin.tie(NULL)

int main() {
    IO;
    int x;
    cin >> x;
    bitset<7> bit(x);
    cout << bit.count();
}
