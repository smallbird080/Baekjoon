#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

#define IO ios::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

int main() {
    IO;
    int m, n;
    cin >> m >> n;
    cin.ignore();
    
    unordered_set<string> phrases;
    
    for (int i = 0; i < m; ++i) {
        string phrase;
        getline(cin, phrase);
        phrases.insert(phrase);
    }
    
    int count = 0;
    
    for (int i = 0; i < n; ++i) {
        string message;
        getline(cin, message);
        
        for (const string& phrase : phrases) {
            if (phrase.substr(0, message.size()) == message) {
                count++;
                break;
            }
        }
    }
    
    cout << count;
    return 0;
}