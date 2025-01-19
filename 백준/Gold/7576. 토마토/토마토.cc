#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point{
    int x;
    int y;
    int status;
    int dist;
    bool visited;

    Point(){}

    Point(int x, int y, int status){
        this->x = x;
        this->y = y;
        this->status = status;
        dist = 0;
        visited = false;
    }

    void visit(int status, int dist){
        this->status = status;
        this->dist = dist;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    int tomato = 0, cnt=0;
    cin >> m >> n;
    vector<vector<Point>> g(n,vector<Point>(m,Point()));
    queue<pair<int,int>> q;
    int num;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> num;
            g[i][j] = Point(i,j,num);
            if (num == -1){
                tomato++;
            }
            else if (num == 1){
                q.push({i,j});
                cnt++;
            }
        }
    }

    int day = 0;
    while (!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        day = g[p.first][p.second].dist;
        g[p.first][p.second].visited = true;
        if (p.first > 0 && g[p.first-1][p.second].status == 0 && !g[p.first-1][p.second].visited){
            q.push({p.first-1, p.second});
            g[p.first-1][p.second].visit(1,day+1);
            cnt++;
        }
        if (p.second > 0 && g[p.first][p.second-1].status == 0 && !g[p.first][p.second-1].visited){
            q.push({p.first, p.second-1});
            g[p.first][p.second-1].visit(1,day+1);
            cnt++;
        }
        if (p.first < n-1 && g[p.first+1][p.second].status == 0 && !g[p.first+1][p.second].visited){
            q.push({p.first+1, p.second});
            g[p.first+1][p.second].visit(1,day+1);
            cnt++;
        }
        if (p.second < m-1 && g[p.first][p.second+1].status == 0 && !g[p.first][p.second+1].visited){
            q.push({p.first, p.second+1});
            g[p.first][p.second+1].visit(1,day+1);
            cnt++;
        }
    }
    if (n*m-tomato > cnt){
        cout << -1;
    }
    else{
        cout << day;
    }

    return 0;
}