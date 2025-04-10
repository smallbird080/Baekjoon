#include <iostream>
#include <vector>
#include <queue>

#define IO ios::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

struct cmp {
    bool operator()(int a, int b) const {
        if (abs(a) == abs(b))
            return a > b;
        return abs(a) > abs(b);
    }
};

int main(){
    IO;

    int n;
    cin >> n;
    priority_queue<int, vector<int>, cmp> pq;
    
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x != 0) {
            pq.push(x);
        } else {
            if (pq.empty()) {
                cout << 0 << "\n";
            } else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }
    
    return 0;
}
