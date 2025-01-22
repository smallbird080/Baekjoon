#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef vector<vector<int>> Paper;

int white=0;
int blue=0;

bool check(const Paper& p, int i, int j, int n){
    if (p[i][j] == 1){
        for (int a=0; a<n; a++){
            for (int b=0; b<n; b++){
                if (p[i+a][j+b]==0)
                    return false;
            }
        }
        blue++;
    }
    else{
        for (int a=0; a<n; a++){
            for (int b=0; b<n; b++){
                if (p[i+a][j+b]==1)
                    return false;
            }
        }
        white++;
    }
    return true;
}

void solve(const Paper& p, int i, int j, int n){
    if (n==1){
        if (p[i][j]==0)
            white++;
        else
            blue++;
        return;
    }
    if (check(p,i,j,n))
        return;
    solve(p,i,j,n/2);
    solve(p,i+n/2,j,n/2);
    solve(p,i,j+n/2,n/2);
    solve(p,i+n/2,j+n/2,n/2);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    Paper paper(n,vector<int>(n));
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin >> paper[i][j];
        }  
    }
    solve(paper,0,0,n);
    cout << white << "\n" << blue;
}