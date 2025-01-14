#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int max_w = 0;
int max_h = 0;

struct Point{
        int cabbage;
        int visited;

        Point(int i){
            cabbage = i;
            visited = 0;
        }
};

int dfs(vector<vector<Point>>& g);

void visit(vector<vector<Point>>& g, int x, int y);

int main(){
    int t,n,m,k;
    cin >> t;
    for (int j=0; j<t; j++){
        cin >> m >> n >> k;
        vector<vector<Point>> ground(m,vector<Point>(n,Point(0)));
        max_w = m;
        max_h = n;

        int a,b; 
        for (int i=0; i<k; i++){
            cin >> a >> b;
            ground[a][b].cabbage = 1;
        }

        int cc = dfs(ground);
        cout << cc << endl;
    }
}


int dfs(vector<vector<Point>>& g){
    int cc = 0;
    for (int x=0; x<max_w; x++){
        for (int y=0; y<max_h; y++){
            if (g[x][y].cabbage == 1 && !g[x][y].visited){
                visit(g,x,y);
                cc++;
            }
        }
    }
    return cc;
}

void visit(vector<vector<Point>>& g, int x, int y){
    g[x][y].visited = 1;
    if (x > 0 && g[x-1][y].cabbage && !g[x-1][y].visited)
        visit(g,x-1,y);
    if (y > 0 && g[x][y-1].cabbage && !g[x][y-1].visited)
        visit(g,x,y-1);
    if (x < max_w - 1 && g[x+1][y].cabbage && !g[x+1][y].visited)
        visit(g,x+1,y);
    if (y < max_h - 1 && g[x][y+1].cabbage && !g[x][y+1].visited)
        visit(g,x,y+1);   
}