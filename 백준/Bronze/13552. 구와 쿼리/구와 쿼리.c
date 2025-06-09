#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int pos[n][3];
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &pos[i][0], &pos[i][1], &pos[i][2]);
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int x, y, z, r;
        scanf("%d %d %d %d", &x, &y, &z, &r);
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (1LL * (pos[j][0] - x) * (pos[j][0] - x) + 1LL * (pos[j][1] - y) * (pos[j][1] - y) + 1LL * (pos[j][2] - z) * (pos[j][2] - z) <= 1LL * r * r) {
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
