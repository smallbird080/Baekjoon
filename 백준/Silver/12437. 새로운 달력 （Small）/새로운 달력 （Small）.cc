#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t, w,m,y;
    cin >> t;
    for (int z=1; z<=t; z++){
        cin >> y >> m >> w;
        int pad = 0;
        int line = 0;
        for (int i=0; i<y; i++){
            int day = m+pad;
            pad = day % w;
            line += day / w;
            if (pad != 0) {
                line++;
            }
        }
        cout << "Case #" << z << ": " << line << "\n";
    }
}