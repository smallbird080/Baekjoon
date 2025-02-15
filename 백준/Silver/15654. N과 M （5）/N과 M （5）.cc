#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>

using namespace std;

int n,m;

struct Node{
    int depth;
    int history[8];
    unordered_set<int> s;
    Node(int n, int d, int* h, unordered_set<int> s){
        depth = d;
        for (int i=0; i<=d; i++)
            history[i] = h[i];
        this->s = s;
        this->s.emplace(n);
    }
    void print(){
        for (int i=0; i<m; i++)
            cout << history[i] << " ";
        cout << "\n";
    }
};

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    cin >> n >> m;
    queue<Node> q;
    vector<int> nums;
    int arr[8];
    for (int i=0; i<n; i++){
        int t;
        cin >> t;
        nums.push_back(t);
    }
    sort(nums.begin(),nums.end());
    for (int i=0; i<n; i++){
        arr[0] = nums[i];
        q.emplace(nums[i],0, arr, unordered_set<int>());
    }
    while (!q.empty()){
        Node cur = q.front();
        q.pop();
        if (cur.depth+1 == m){
            cur.print();
            continue;
        }
        for (int i : nums){
            if (cur.s.find(i) != cur.s.end())
                continue;
            cur.history[cur.depth+1] = i;
            q.emplace(i, cur.depth+1, cur.history, cur.s);
        }
    }
}