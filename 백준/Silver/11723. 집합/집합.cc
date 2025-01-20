#include <iostream>
#include <bitset>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m, num;
    bitset<20> set;
    cin >> m;
    string line;
    while (m--){
        cin >> line;
        if (!line.compare("add")){
            cin >> num;
            set.set(num-1);
        }
        else if (!line.compare("remove")){
            cin >> num;
            set.reset(num-1);
        }
        else if (!line.compare("check")){
            cin >> num;
            cout << set[num-1] << "\n";
        }
        else if (!line.compare("toggle")){
            cin >> num;
            set.flip(num-1);
        }
        else if (!line.compare("all")){
            set.set();
        }
        else if (!line.compare("empty")){
            set.reset();
        }
    }
    
    return 0;
}