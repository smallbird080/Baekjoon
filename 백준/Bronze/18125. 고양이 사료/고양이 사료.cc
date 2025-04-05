#include <iostream>
#include <vector>

#define IO ios::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

int main(){
    IO;
    int r,c;
    cin >> r >> c;
    vector<vector<int>> pic(c,vector<int>(r));
    for (int i=0; i<c; i++){
        for (int j=0; j<r; j++)
            cin >> pic[i][j];
    }
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            int num;
            cin >> num;
            if (num != pic[c-j-1][i]){
                cout << "|>___/|     /}\n"
                     << "| O O |    / }\n"
                     << "( =0= )\"\"\"\"  \\\n"
                     << "| ^  ____    |\n"
                     << "|_|_/    ||__|\n";
                return 0;
            }
        }
    }
    cout << "|>___/|        /}\n"
         << "| O < |       / }\n"
         << "(==0==)------/ }\n"
         << "| ^  _____    |\n"
         << "|_|_/     ||__|\n";
}
