#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
int arr[8];

void solve(int num, int d){
    if (d==m-1){
        for (int i=0; i<d; i++)
            cout << arr[i] << " ";
        cout << num;
        cout << "\n";
        return;
    }
    arr[d] = num;
    for (int i=num; i<=n; i++)
        solve(i,d+1);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    cin >> n >> m;
    for (int i=1; i<=n; i++)
        solve(i,0);
}