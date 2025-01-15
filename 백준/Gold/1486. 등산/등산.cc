#include <iostream>
#include <vector>
#include <cmath>

#define MIN(a,b) ((a) < (b) ? (a) : (b))

using namespace std;

int** floyd(int** arr, int n);

int main(){
    int n,m,t,d;
    cin >> n >> m >> t >> d;
    int* map = new int[n*m];
    for (int i=0; i<n; i++){
        string str;
        cin >> str;
        for (int j=0; j<m; j++){
            if (str[j] < 91)
                map[i*m+j] = str[j]-65; // Corrected index calculation
            else
                map[i*m+j] = str[j]-97+26; // Corrected index calculation
        }
    }

    int** w = new int*[n*m];
    for (int i=0; i<n*m; i++){
        w[i] = new int[n*m];
        for (int j=0; j<n*m; j++){
            if (i % m > 0 && j == i-1 && abs(map[j] - map[i]) <= t){
                w[i][j] = map[i] >= map[j] ? 1 : static_cast<int>(pow(map[j] - map[i], 2)); // Cast to int
            }
            else if (i / m > 0 && j == i-m && abs(map[j] - map[i]) <= t){
                w[i][j] = map[i] >= map[j] ? 1 : static_cast<int>(pow(map[j] - map[i], 2)); // Cast to int
            }
            else if (i % m < m-1 && j == i+1 && abs(map[j] - map[i]) <= t){
                w[i][j] = map[i] >= map[j] ? 1 : static_cast<int>(pow(map[j] - map[i], 2)); // Cast to int
            }
            else if (i / m < n-1 && j == i+m && abs(map[j] - map[i]) <= t){
                w[i][j] = map[i] >= map[j] ? 1 : static_cast<int>(pow(map[j] - map[i], 2)); // Cast to int
            }
            else
                w[i][j] = 9999999;
        }
    }

    w = floyd(w, n*m);
    int maxH = map[0];
    for (int i=1; i<n*m; i++){
        if (w[0][i] + w[i][0] <= d && maxH < map[i])
            maxH = map[i];
    }

    cout << maxH;

    delete[] map;
    for (int i=0; i<n; i++)
        delete[] w[i];
    delete[] w;
    return 0;
}

int** floyd(int** arr, int n){
    int** pd = arr;
    int** cd;
    for (int k=0; k<n; k++){
        cd = new int*[n];
        for (int i=0; i<n; i++)
            cd[i] = new int[n];

        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                cd[i][j] = MIN(pd[i][j], pd[i][k] + pd[k][j]);
            }
        }
        for (int i=0; i<n; i++)
            delete[] pd[i];
        delete[] pd;
        pd = cd;
    }
    return cd;
}
