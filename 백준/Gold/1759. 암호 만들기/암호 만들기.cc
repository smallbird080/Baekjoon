#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

#define IO ios::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

int l,c;
char pwd[15];
char chars[15];
unordered_set<char> vowel = {'a','e','i','o','u'};

bool isVowel(char c){
    return vowel.count(c);
}

void solve(int len, int idx, int v, int s){
    if (len == l && v && s >= 2){
        for (int i=0; i<l; i++)
            cout << pwd[i];
        cout << "\n";
        return;
    }
    
    for (int i=idx+1; i<c; i++){
        pwd[len] = chars[i];
        if (isVowel(chars[i]))
            solve(len+1,i,v+1,s);
        else
            solve(len+1,i,v,s+1);
    }
}

int main() {
    IO;
    cin >> l >> c;
    for (int i=0; i<c; i++)
        cin >> chars[i];
    sort(chars,chars+c);
    for (int i=0; i<=c-l; i++){
        char alphabet = chars[i];
        pwd[0] = alphabet;
        if (isVowel(alphabet))
            solve(1, i, 1, 0);
        else
            solve(1, i, 0, 1);
    }
}