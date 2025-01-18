#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Pos{
    bool visited;
    int dist;

    Pos(){
        visited = false;
        dist = 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin >> n >> k;
    Pos* arr = new Pos[100001];
    arr[n].visited = true;
    queue<int> q;
    q.push(n);
    int pos;
    while (!q.empty()){
        pos = q.front();
        q.pop();
        if (pos == k){
            break;
        }
        if (pos-1 >=0 && !arr[pos-1].visited){
            q.push(pos-1);
            arr[pos-1].visited = true;
            arr[pos-1].dist = arr[pos].dist + 1;
        }
        if (pos+1 <= 100000 && !arr[pos+1].visited){
            q.push(pos+1);
            arr[pos+1].visited = true;
            arr[pos+1].dist = arr[pos].dist + 1;
        }
        if (pos*2 <= 100000 && !arr[pos*2].visited){
            q.push(pos*2);
            arr[pos*2].visited = true;
            arr[pos*2].dist = arr[pos].dist + 1;
        }
    }
    cout << arr[pos].dist;
    delete[] arr;
    return 0;
}
