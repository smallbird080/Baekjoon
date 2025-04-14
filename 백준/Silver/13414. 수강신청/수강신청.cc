#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define IO ios::sync_with_stdio(false);cin.tie(NULL)

int main() {
    IO;
    int k,l;
    cin >> k >> l;
    vector<pair<int,string>> priority;
    unordered_map<string,int> nums(l);
    for (int i=0; i<l; i++){
        string num;
        cin >> num;
        nums[num] = i;
    }

    for (auto i : nums){
        priority.emplace_back(i.second,i.first);
    }

    sort(priority.begin(), priority.end());

    int cnt = 0;
    for (auto i : priority){
        cout << i.second << "\n";
		cnt++;
		if (cnt == k) break;
    }
}
