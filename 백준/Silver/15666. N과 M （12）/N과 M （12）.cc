#include <iostream>
#include <vector>
#include <set>

#define IO ios::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

int n,m;
int arr[8];
set<int> s;

void solve(set<int>::iterator iter, int len){
    if (len==m){
        for (int i=0; i<m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for (set<int>::iterator it = iter; it != s.end(); it++){
        arr[len] = *it;
        solve(it,len+1);
    }
}

int main() {
    IO;
    cin >> n >> m;
    int num;
    for (int i=0; i<n; i++){
        cin >> num;
        s.emplace(num);
    }

    for (set<int>::iterator it = s.begin(); it != s.end(); it++){
        arr[0] = *it;
        solve(it,1);
    }
}