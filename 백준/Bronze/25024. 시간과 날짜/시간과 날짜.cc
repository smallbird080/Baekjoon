#include <iostream>

#define IO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

int main() {
    IO;
    int n;
    cin >> n;
    
    while(n--) {
        int x, y;
        cin >> x >> y;
        
        bool validTime = false;
        if(x >= 0 && x <= 23 && y >= 0 && y <= 59) {
            validTime = true;
        }

        bool validDate = false;
        if(x >= 1 && x <= 12) {
            int daysInMonth[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if(y >= 1 && y <= daysInMonth[x-1]) {
                validDate = true;
            }
        }
        
        cout << (validTime ? "Yes" : "No") << " " << (validDate ? "Yes" : "No") << "\n";
    }
    
    return 0;
}
