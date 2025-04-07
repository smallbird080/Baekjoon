#include <bits/stdc++.h>
using namespace std;

static int toCents(const string &s) {
    int dotPos = -1;
    for(int i = 0; i < (int)s.size(); i++){
        if(s[i] == '.'){
            dotPos = i;
            break;
        }
    }
    int dollars = 0, cents = 0;
    if(dotPos == -1) {
        dollars = stoi(s);
    } else {
        dollars = stoi(s.substr(0, dotPos));
        string centStr = s.substr(dotPos + 1);
        if(centStr.size() == 1) centStr += '0';
        else if(centStr.size() > 2) centStr = centStr.substr(0, 2);
        if(!centStr.empty()) cents = stoi(centStr);
    }
    return dollars * 100 + cents;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string sPS, sP1, sP2;
    cin >> sPS >> sP1 >> sP2;

    int pS = toCents(sPS);
    int p1 = toCents(sP1);
    int p2 = toCents(sP2);

    if(pS == 0){
        cout << 0 << " " << 0 << "\n";
        return 0;
    }

    bool found = false;
    int maxX = pS / p1;

    for(int x = 0; x <= maxX; x++){
        int cost = x * p1;
        int remain = pS - cost;
        if(remain >= 0 && remain % p2 == 0){
            int y = remain / p2;
            cout << x << " " << y << "\n";
            found = true;
        }
    }
    if(!found) cout << "none\n";
    return 0;
}
