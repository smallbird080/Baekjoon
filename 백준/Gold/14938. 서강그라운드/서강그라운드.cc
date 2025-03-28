#include <iostream>
#include <vector>
#include <queue>

#define INF 10000000
#define IO ios::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

int main() {
    IO;
    int n,m,r;
    cin >> n >> m >> r;
    vector<vector<int>> D(n,vector<int>(n,INF));
    vector<int> spot(n);
    for (int i=0; i<n; i++){
        cin >> spot[i];
        D[i][i] = 0;
    }
    for (int i=0; i<r; i++){
        int u,v,w;
        cin >> u >> v >> w;
        D[u-1][v-1] = min(D[u-1][v-1],w);
        D[v-1][u-1] = min(D[v-1][u-1],w);
    }
    for (int k=0; k<n; k++){
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++)
                D[i][j] = min(D[i][j], D[i][k]+D[k][j]);
        }
    }
    int result = 0;
    for (int i=0; i<n; i++){
        int total = 0;
        for (int j=0; j<n; j++){
            if (D[i][j] <= m)
            total += spot[j];
        }
        result = max(result,total);
    }
    cout << result;
}
