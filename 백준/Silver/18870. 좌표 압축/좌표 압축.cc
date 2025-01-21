#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,coord;
    cin >> n;
    map<int,int> dict;
    set<int> order;
    vector<int> record(n);
    for (int i=0; i<n; i++){
        cin >> coord;
        order.emplace(coord);
        record[i] = coord;
    }

    int idx=0;
    for (set<int>::iterator it = order.begin(); it != order.end(); it++){
        dict[*it] = idx++;
    }

    for (int num : record){
        cout << dict[num] << " ";
    }
}