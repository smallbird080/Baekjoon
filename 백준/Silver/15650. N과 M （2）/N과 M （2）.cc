#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n,m;

struct Node{
    int num;
    int depth;
    int history[8];

    Node(int n, int d, int* h){
        num = n;
        depth = d;
        for (int i=0; i<=d; i++)
            history[i] = h[i];
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
    int arr[8];
    for (int i=1; i<=n-m+1; i++){
        arr[0] = i;
        q.emplace(i,0, arr);
    }
    while (!q.empty()){
        Node cur = q.front();
        q.pop();
        if (cur.depth+1 == m){
            cur.print();
            continue;
        }
        for (int i=cur.num+1; i<=n-(m-2-cur.depth); i++){
            cur.history[cur.depth+1] = i;
            q.emplace(i,cur.depth+1, cur.history);
        }
    }
    
}