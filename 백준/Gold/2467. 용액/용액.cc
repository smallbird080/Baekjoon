#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define IO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;


int main(){
    IO;
    int n;
    cin >> n;
    vector<int> sample(n);
    for (int i=0; i<n; i++)
        cin >> sample[i];
    int result = __INT_MAX__;
    int s = 0;
    int e = n-1;
    int x,y,resX,resY;
    resX = resY = sample[0];
    for (int i=0; i<n; i++){
        x = sample[s];
        y = sample[e];
        int calc = x+y;
        if (calc > 0)
            e--;
        else if (calc < 0)
            s++;
        else{
            cout << x << ' ' << y;
            return 0;
        }
        if (abs(result) >= abs(calc)){
            result = calc;
            resX = x;
            resY = y;
        }
        if (e <= s)
            break;
    }
    
    cout << resX << ' ' << resY;
}