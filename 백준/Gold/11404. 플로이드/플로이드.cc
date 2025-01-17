#include <iostream>
#include <vector>

#define INF 100000*(100-1)+1
using namespace std;

typedef vector<vector<int>> Graph;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int v, e;
    cin >> v >> e;
    Graph g(v,vector<int>(v,INF));
    for (int i=0; i<v; i++){
        for (int j=0; j<v; j++){
            if (i==j)
                g[i][j] = 0;
            else
                g[i][j] = INF;
        }
    }

    int from,to,w;
    for (int i=0; i<e; i++){
        cin >>from>>to>>w;
        g[from-1][to-1] = min(g[from-1][to-1], w);
    }

    for (int k = 0; k < v; k++) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    for (int i=0; i<v; i++){
        for (int j=0; j<v; j++){
            if (g[i][j] == INF)
                cout << 0 << " ";
            else 
                cout << g[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}