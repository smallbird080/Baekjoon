#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Graph;

int findMaxSum(const Graph& g, int n, int m, int x, int y);

int main() {
    int n, m;
    cin >> n >> m;
    Graph g(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    int maxSum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int result = findMaxSum(g, n, m, i, j);
            maxSum = max(maxSum, result);
        }
    }
    cout << maxSum;
    return 0;
}

int findMaxSum(const Graph& g, int n, int m, int x, int y) {
    int maxSum = 0;
    vector<vector<int>> tetrominoes = {
        // I 
        {0, 1, 0, 2, 0, 3},
        {1, 0, 2, 0, 3, 0},
        // O 
        {0, 1, 1, 0, 1, 1},
        // T 
        {1, 0, -1, 0, 0, 1},
        {1, 0, -1, 0, 0, -1},
        {0, 1, 0, -1, 1, 0},
        {0, 1, 0, -1, -1, 0},
        // L 
        {1, 0, 2, 0, 2, 1},
        {0, 1, 0, 2, 1, 2},
        {1, 0, 2, 0, 2, -1},
        {0, 1, 0, 2, -1, 2},
        {1, 0, 1, 1, 1, 2},
        {-1, 0, -1, 1, -1, 2},
        {0, 1, 1, 1, 2, 1},
        {0, -1, 1, -1, 2, -1},
        // S 
        {1, 0, 1, 1, 2, 1},
        {0, 1, -1, 1, -1, 2},
        {1, 0, 1, -1, 2, -1},
        {0, 1, 1, 1, 1, 2}
    };

    for (const auto& t : tetrominoes) {
        int sum = g[x][y];
        bool valid = true;
        for (int i = 0; i < t.size(); i += 2) {
            int ny = y + t[i];
            int nx = x + t[i + 1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                valid = false;
                break;
            }
            sum += g[nx][ny];
        }
        if (valid) {
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}