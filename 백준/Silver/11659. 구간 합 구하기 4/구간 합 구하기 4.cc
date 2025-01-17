#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n,m;
    std::cin >> n >> m;
    int* arr[100000];
    arr[0] = 0;
    int num;
    for (int i=1; i<=n; i++){
        std::cin >> num;
        arr[i] = arr[i-1] + num;
    }
    int a,b;
    for (int i=0; i<m; i++){
        std::cin >> a >> b;
        std::cout << arr[b] - arr[a-1] << "\n";
    }
}
