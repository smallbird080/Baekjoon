#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Line{
    int l;
    int m;
    int r;
};


int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin >> n;
    int l[2];
    int m[2];
    int r[2];
    l[0] = 0;
    m[0] = 0;
    r[0] = 0;
    vector<Line> game(n);
    for (int i=0; i<n; i++)
        cin >> game[i].l >> game[i].m >> game[i].r;
    for (int i=1; i<=n; i++){
        l[1] = max(m[0],l[0]) + game[i-1].l;
        m[1] = max({l[0],r[0],m[0]}) + game[i-1].m;
        r[1] = max(m[0],r[0]) + game[i-1].r;
        l[0] = l[1];
        m[0] = m[1];
        r[0] = r[1];
    }
    cout << max({l[0],m[0],r[0]}) << "\n";
    l[0] = 0;
    m[0] = 0;
    r[0] = 0;
    for (int i=1; i<=n; i++){
        l[1] = min(m[0],l[0]) + game[i-1].l;
        m[1] = min({l[0],r[0],m[0]}) + game[i-1].m;
        r[1] = min(m[0],r[0]) + game[i-1].r;
        l[0] = l[1];
        m[0] = m[1];
        r[0] = r[1];
    }
    cout << min({l[0],m[0],r[0]}) << "\n";
}