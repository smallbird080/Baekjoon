#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

#define IO ios::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

int main() {
    IO;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> lis;
    vector<int> parent(n, -1);
    vector<int> lis_indices;

    for (int i = 0; i < n; i++) {
        auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
        int idx = distance(lis.begin(), it);

        if (it == lis.end()) {
            lis.push_back(arr[i]);
            lis_indices.push_back(i);
        } else {
            *it = arr[i];
            lis_indices[idx] = i;
        }

        if (idx > 0)
            parent[i] = lis_indices[idx - 1];
    }

    cout << lis.size() << "\n";

    return 0;
}