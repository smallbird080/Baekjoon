#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

#define IO ios::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

void makeStar(vector<vector<char>>& star, int size, int r, int c){
    if (size==3){
        star[r][c] = '*';
        star[r+1][c-1] = '*';
        star[r+1][c+1] = '*';
        for (int i=0; i<5; i++)
            star[r+2][c-2+i] = '*';
        return;
    }
    size /= 2;
    makeStar(star,size,r,c);
    makeStar(star,size,r+size,c-size);
    makeStar(star,size,r+size,c+size);
}

int main() {
    IO;
    int n;
    cin >> n;
    vector<vector<char>> star(n,vector<char>(2*n+1,' '));
    makeStar(star,n,0,n-1);
    for (int i=0; i<n; i++){
        for (int j=0; j<2*n+1; j++){
            cout << star[i][j];
        }
        cout << "\n";
    }
}