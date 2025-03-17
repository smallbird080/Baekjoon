#include <iostream>
#include <vector>
#include <string>

#define IO ios::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

string editWord(const string& s){
    string newStr;
    for (int i=0; i<s.length(); i++){
        char c = s[i];
        if (c == 45 || (c > 64 && c < 91) || (c > 96 && c < 123)){
            if (c < 97 && c != 45)
                c += 32;
            newStr.push_back(c);
        }
        else {
            if (i < s.length()-1){
                string after = editWord(s.substr(i+1));
                newStr = newStr.length() >= after.length() ? newStr : after;
            }
            break;
        }
    }
    return newStr;
}

int main() {
    IO;
    string max;
    while (true){
        string word;
        cin >> word;
        if (word == "E-N-D")
            break;
        string s = editWord(word);
        max = max.length() >= s.length() ? max : s;
    }
    cout << max;
}