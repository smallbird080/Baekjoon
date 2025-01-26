#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    int n,m,num,x1,y1,x2,y2;
    cin >> n >> m;
    vector<vector<int>> table(n+1,vector<int>(n+1,0));
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> num;
            table[i][j] = table[i][j-1] + num;
        }
    }

    while (m--){
        int sum = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i=x1; i<=x2; i++){
            sum += table[i][y2] - table[i][y1-1];
        }
        cout << sum << "\n";
    }
}