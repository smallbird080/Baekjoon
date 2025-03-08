#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define IO ios::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

int main() {
    IO;
    int n;
    cin >> n;
    map<char,int> alphabet;
    char c;
    for (int i=0; i<n/2; i++){
        cin >> c;
        if (alphabet.count(c))
            alphabet[c]++;
        else
            alphabet[c] = 1;
    }
    if (n&1)
        cin >> c;
    for (int i=0; i<n/2; i++){
        cin >> c;
        if (alphabet.count(c))
            alphabet[c]++;
        else
            alphabet[c] = 1;
    }
    for (const auto& pair : alphabet) {
        if (pair.second % 2 != 0) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}