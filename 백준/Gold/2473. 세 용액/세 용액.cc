#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define IO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;


int main() {
    IO;
    int n;
    cin >> n;
    vector<int> sample(n);
    for (int i = 0; i < n; i++)
        cin >> sample[i];
    sort(sample.begin(), sample.end());
    long result = __LONG_MAX__;
    long x, y, z, resX, resY, resZ;
    for (int i=0; i<n-2; i++){
        int s = i;
        int m = i+1;
        int e = n-1;
        x = sample[s];
        while (m < e){
            y = sample[m];
            z = sample[e];
            long calc = x + y + z;
            if (abs(result) >= abs(calc)){
                result = calc;
                resX = x;
                resY = y;
                resZ = z;
            }
            if (calc > 0){
                e--;
            }
            else if (calc < 0){
                m++;
            }
            else{
                 cout << resX << ' ' << resY << ' ' << resZ;
                return 0;
            }
        }
    }
    

    cout << resX << ' ' << resY << ' ' << resZ;
}