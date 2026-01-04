#include <iostream>
#include <vector>
#include <algorithm>

#define IO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

int main(){
    IO;
    int n;
    cin >> n;
    vector<int> stair(n+2);
    for (int i=2; i<n+2; i++)
        cin >> stair[i];
    stair[0] = stair[1] = 0;

    vector<int> cont1(stair);
    vector<int> cont2(stair);

    for (int i=2; i<n+2; i++){
        cont1[i] += max(cont1[i-2], cont2[i-2]);
        cont2[i] += cont1[i-1];
    }

    cout << max(cont1[n+1], cont2[n+1]);
}