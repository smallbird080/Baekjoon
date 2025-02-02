#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int,int>> cows(n);
    for (int i=0; i<n; i++){
        cin >> cows[i].first >> cows[i].second;
    }
    sort(cows.begin(),cows.end(),[](pair<int,int>p1, pair<int,int>p2) -> bool {return p1.first < p2.first;});
    int time = 0;
    for (pair<int,int> cow : cows){
        if (cow.first > time)
            time = cow.first;
        time += cow.second;
    }
    cout << time;
}