#include <iostream>
#include <vector>

#define INF 800*200000+1

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    int n,e;
    cin >> n >> e;
    vector<vector<int>> map(n,vector<int>(n,INF));
    for (int i=0; i<n; i++)
        map[i][i] = 0;
    while (e--){
        int a,b,c;
        cin >> a >> b >> c;
        map[a-1][b-1] = c;
        map[b-1][a-1] = c;
    }
    int v1,v2;
    cin >> v1 >> v2;
    for (int k=0; k<n; k++){
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                map[i][j] = min(map[i][j], map[i][k]+map[k][j]);
            }
        }
    }

    int result = min(map[0][v1-1]+map[v1-1][v2-1]+map[v2-1][n-1], map[0][v2-1]+map[v2-1][v1-1]+map[v1-1][n-1]);
    if (result >= INF)
        cout << -1;
    else
        cout << result;
}