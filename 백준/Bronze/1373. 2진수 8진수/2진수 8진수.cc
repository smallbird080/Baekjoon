#include <iostream>
#include <vector>
#include <string>

#define IO ios::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

int getOct(const string& bin){
    return 4*int(bin[0]-'0') + 2*int(bin[1]-'0') + int(bin[2]-'0');
}

int main() {
    IO;
    string binary;
    cin >> binary;
    int len = binary.length();
    int pad = len%3;
    if (pad != 0) {
        binary = string(3 - pad, '0') + binary;
    }
    len = binary.length();
    for (int i=0; i<len; i+=3){
        cout << getOct(binary.substr(i,3));
    }
}