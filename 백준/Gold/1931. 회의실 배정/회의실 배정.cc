#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compareF(pair<int,int> a, pair<int,int> b){
    if (a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main(){
    int n;
    vector<pair<int,int>> schedule;
    cin >> n;
    for (int i=0; i<n; i++){
        int s,e;
        cin >> s >> e;
        schedule.push_back({s,e});
    }
    sort(schedule.begin(), schedule.end(), compareF);
    int end = 0;
    int cnt = 0;
    for (pair<int,int> meeting : schedule){
        if (meeting.first >= end){
            cnt++;
            end = meeting.second;
        }
    }
    cout << cnt;
}
