#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

#define IO ios::sync_with_stdio(false);cin.tie(NULL)

int n;
int post[100001];
unordered_map<int, int> inIndex; 

void preorder(int inStart, int inEnd, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd)
        return;

    int root = post[postEnd];
    cout << root << " ";

    int inRoot = inIndex[root];
    int leftSize = inRoot - inStart;

    preorder(inStart, inRoot - 1, postStart, postStart + leftSize - 1);
    preorder(inRoot + 1, inEnd, postStart + leftSize, postEnd - 1);
}

int main() {
    IO;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int in;
        cin >> in;
        inIndex[in] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> post[i];
    }

    preorder(1, n, 1, n);
    return 0;
}
