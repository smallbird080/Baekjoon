#include <iostream>
#include <vector>
#include <queue>

#define IO ios::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

char number[10][5][4] = {
    {"***", "* *", "* *", "* *", "***"},
    {"  *", "  *", "  *", "  *", "  *"},
    {"***", "  *", "***", "*  ", "***"},
    {"***", "  *", "***", "  *", "***"},
    {"* *", "* *", "***", "  *", "  *"},
    {"***", "*  ", "***", "  *", "***"},
    {"***", "*  ", "***", "* *", "***"},
    {"***", "  *", "  *", "  *", "  *"},
    {"***", "* *", "***", "* *", "***"},
    {"***", "* *", "***", "  *", "***"} 
};

bool isValidDigit(const vector<string>& code, int pos, int& digit) {
    for (digit = 0; digit < 10; digit++) {
        bool match = true;
        for (int i = 0; i < 5 && match; i++)
            for (int j = 0; j < 3 && match; j++) {
                if (code[i][pos + j] != number[digit][i][j])
                    match = false;
            }
        if (match) 
            return true;
    }
    return false;
}

int main() {
    IO;
    vector<string> input(5);
    for (int i=0; i<5; i++) 
        getline(cin, input[i]);
    
    int res = 0;
    bool invalid = false;
    for (int i=0; i<input[0].size(); i+=4) {
        int digit;
        if (!isValidDigit(input, i, digit)) {
            invalid = true;
            break;
        }
        res = res * 10 + digit;
    }
    cout << ((invalid || res % 6 != 0) ? "BOOM!!" : "BEER!!") << "\n";
}
