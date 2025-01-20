#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,cnt=0;
    set<string> names, idk;
    cin >> n >> m;
    string name;
    while(n--){
        cin >> name;
        names.insert(name);
    }

    while(m--){
        cin >> name;
        set<string>::iterator iter = names.find(name);
        if (iter != names.end()){
            cnt++;
            idk.insert(*iter);
        }
    }

    cout << cnt << "\n";
    for (string s : idk)
        cout << s << "\n";
    
    return 0;
}