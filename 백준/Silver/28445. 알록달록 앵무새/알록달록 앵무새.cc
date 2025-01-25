#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    set<string> colors;
    string c;
    for (int i=0; i<4; i++){
        cin >> c;
        colors.emplace(c);
    }
    for (auto it1=colors.begin(); it1!=colors.end(); it1++){
        for (auto it2=colors.begin(); it2!=colors.end(); it2++){
            cout << *it1 << " " << *it2 << "\n";
        }
    }
}