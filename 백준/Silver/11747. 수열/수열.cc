#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int convert(const vector<int>& d, int idx, int len){
    int result = 0;
    for (int i=0; i<len; i++){
        result *= 10;
        result += d[idx+i];
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> d(n);
    for (int i=0; i<n; i++){
        cin >> d[i];
    }
    unordered_set<int> found(4000);
    for (int i=1; i<=4; i++){
        for (int j=0; j<=n-i; j++){
            found.insert(convert(d,j,i));
        }
    }
    int num = 0;
    while(true){
        if (found.find(num) == found.end())
            break;
        num++;
    }
    cout << num;
}