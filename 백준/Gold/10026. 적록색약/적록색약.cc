#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<vector<pair<int,bool>>> Graph;

int dfs(Graph& g, int n);

void visit(Graph& g, int n, int x, int y);

int main(){
    int n;
    cin >> n;
    Graph rgb(n,vector<pair<int,bool>>(n, {0,false}));
    Graph rb(n,vector<pair<int,bool>>(n, {0,false}));
    string line;
    for (int i=0; i<n; i++){
        cin >> line;
        for (int j=0; j<n; j++){
            if (line[j] == 'R'){
                rgb[i][j].first = 1;
                rb[i][j].first = 1;
            }
            else if (line[j] == 'G'){
                rgb[i][j].first = 2;
                rb[i][j].first = 1;
            }
            else if (line[j] == 'B'){
                rgb[i][j].first = 3;
                rb[i][j].first = 3;
            }
        }
    }
    cout << dfs(rgb, n) << " " << dfs(rb,n);
}

int dfs(Graph& g, int n){
    int cc = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (!g[i][j].second){
                cc++;
                visit(g,n,i,j);
            }
        }
    }
    return cc;
}

void visit(Graph& g, int n, int x, int y){
    g[x][y].second = true;
    if (x > 0 && g[x-1][y].first == g[x][y].first && !g[x-1][y].second){
        visit(g,n,x-1,y);
    }
    if (y > 0 && g[x][y-1].first == g[x][y].first && !g[x][y-1].second){
        visit(g,n,x,y-1);
    }
    if (x < n-1 && g[x+1][y].first == g[x][y].first && !g[x+1][y].second){
        visit(g,n,x+1,y);
    }
    if (y < n-1 && g[x][y+1].first == g[x][y].first && !g[x][y+1].second){
        visit(g,n,x,y+1);
    }
}
