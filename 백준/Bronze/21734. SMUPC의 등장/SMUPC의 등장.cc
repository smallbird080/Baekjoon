#include <iostream>
#define IO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

int main() {
    IO;
    string s;
    cin >> s;
    for (char c : s){
        int ascii = c;
        int sum = 0;
        while (ascii > 0){
            int digit = ascii % 10;
            sum += digit;
            ascii /= 10;
        }
        for (int i=0; i<sum; i++)
            cout << c;
        cout << '\n';
    }
    return 0;
}
