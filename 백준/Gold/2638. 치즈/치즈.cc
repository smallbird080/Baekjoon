#include <iostream>
#include <vector>
#include <queue>

#define IO ios::sync_with_stdio(false);cin.tie(NULL)
#define Map vector<vector<Point>>

using namespace std;

int n,m;
int direction[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

struct Point{
    bool cheese;
    bool visited;
    int airCnt;

    void melt(){
        if (airCnt >= 2)
            cheese = false;
    }

    void rst(){
        airCnt = 0;
        visited = false;
    }

    void rst(bool _cheese){
        cheese = _cheese;
        airCnt = 0;
        visited = false;
    }
};

bool spendOneHour(Map& G){
    bool hasCheese = false;
    queue<pair<int,int>> q;
    q.emplace(0,0);
    G[0][0].visited = true;
    while (!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i=0; i<4; i++){
            int newR = r + direction[i][0];
            int newC = c + direction[i][1];
            if (newR < 0 || newC < 0 || newR >= n || newC >= m)
                continue;
            if (G[newR][newC].visited)
                continue;
            if (G[newR][newC].cheese){
                (G[newR][newC].airCnt)++;
                hasCheese = true;
            }
            else{
                q.emplace(newR,newC);
                G[newR][newC].visited = true;
            }
        }
    }
    return hasCheese;
}

int main() {
    IO;
    cin >> n >> m;
    Map G(n,vector<Point>(m));
    for (int i=0; i<n; i++){
        bool c;
        for (int j=0; j<m; j++){
            cin >> c;
            G[i][j].rst(c);
        }
    }
    int time = 0;
    while (spendOneHour(G)){
        time++;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (G[i][j].cheese)
                    G[i][j].melt();
                G[i][j].rst();
            }
        }
    }
    cout << time;
}