#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    int n;
    string word;
    while (true){
        cin >> n;
        if (!n)
            break;
        map<string,string> s;
        while (n--){
            cin >> word;
            string origin = word;
            transform(word.begin(), word.end(), word.begin(),
                [](unsigned char c){ return std::tolower(c); });
            s.emplace(word,origin);
        }
        cout << (*s.begin()).second << "\n";
    }
}