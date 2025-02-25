#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

#define INF 1000000000

using namespace std;

struct DisjSet{
    vector<int> arr;
    unordered_set<int> roots;

    DisjSet(int n, vector<int>& r){
        arr = vector<int>(n);
        for (int i=0; i<n; i++)
            arr[i] = -1;
        for (int i : r){
            roots.emplace(i);
        }
    }

    int find(int x){
        if (arr[x] < 0)
            return x;
        arr[x] = find(arr[x]);
        return arr[x];
    }

    void uni_no_opt(int x, int y){
        if (x==y)
            return;
        if (roots.count(x) && !roots.count(y))
            arr[y] = x;
        else
            arr[x] = y;
    }
};


int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    int n,m,x,p;
    cin >> n >> m >> x;
    vector<int> ppl(x);
    vector<vector<int>> party(m);
    for (int i=0; i<x; i++)
    cin >> ppl[i];
    DisjSet s(n+1,ppl);
    for (int j=0; j<m; j++){
        cin >> p;
        int x,y;
        cin >> x;
        party[j].push_back(x);
        for (int i=0; i<p-1; i++){
            cin >> y;
            party[j].push_back(y);
            s.uni_no_opt(s.find(x),s.find(y));
            y=x;
        }
    }
    if (x == 0){
        cout << m;
        return 0;
    }
    for (vector<int> pt : party){
        for (int person : pt){
            if (s.roots.count(s.find(person))){
                m--;
                break;
            }
        }
    }
    cout << m;
}