#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    int t,k,n;
    char c;
    multiset<int> q;
    cin >> t;
    while (t--){
        q = multiset<int>();
        cin >> k;
        while (k--){
            cin >> c >> n;
            if (c == 'D' && !q.empty()){
                if (n==1)
                    q.erase(prev(q.end()));
                else
                    q.erase(q.begin());
            }
            else if (c == 'I')
                q.emplace(n);
        }
        if (q.empty())
            cout << "EMPTY\n";
        else
            cout << *q.rbegin() << " " << *q.begin() << "\n";
    }
}