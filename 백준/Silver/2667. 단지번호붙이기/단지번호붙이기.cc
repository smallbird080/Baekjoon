#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct Point{
        int house;
        int visited;

        Point(int i){
            house = i;
            visited = 0;
        }
};

int dfs(vector<vector<Point>>& g, int n, vector<int>& arr);

void visit(vector<vector<Point>>& g, int x, int y, int n, vector<int>& arr);

int main(){
    int n;
    cin >> n;
    string line;
    vector<vector<Point>> map(n,vector<Point>(n,Point(0)));
    vector<int> arr;
    for (int i=0; i<n; i++){
        cin >> line;
        for (int j=0; j<n; j++){
            map[i][j] = (line[j] == '1');
        }
    }
    int cc = dfs(map, n, arr);
    cout << cc << endl;
    sort(arr.begin(), arr.end());
    for (int i : arr){
        cout << i + 1 << endl;
    }
}


int dfs(vector<vector<Point>>& g, int n, vector<int>& arr){
    int cc = 0;
    for (int x=0; x<n; x++){
        for (int y=0; y<n; y++){
            if (g[x][y].house == 1 && !g[x][y].visited){
                arr.push_back(0);
                visit(g,x,y,n,arr);
                cc++;
            }
        }
    }
    return cc;
}

void visit(vector<vector<Point>>& g, int x, int y, int n, vector<int>& arr){
    int idx = arr.size()-1;
    g[x][y].visited = 1;
    if (x > 0 && g[x-1][y].house && !g[x-1][y].visited) {
        visit(g,x-1,y,n,arr);
        arr[idx]++;
    }
    if (y > 0 && g[x][y-1].house && !g[x][y-1].visited) {
        visit(g,x,y-1,n,arr);
        arr[idx]++;
    }
    if (x < n - 1 && g[x+1][y].house && !g[x+1][y].visited) {
        visit(g,x+1,y,n,arr);
        arr[idx]++;
    }
    if (y < n - 1 && g[x][y+1].house && !g[x][y+1].visited) {
        visit(g,x,y+1,n,arr);
        arr[idx]++;
    }
}