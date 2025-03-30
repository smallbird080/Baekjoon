#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#define IO ios::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

int main(){
    IO;

    while(true) {
        int r, s;
        cin >> r >> s;
        if(!cin || (r == 0 && s == 0)) {
            break;
        }

        unordered_map<int,int> freq;

        for(int i = 0; i < r; i++){
            for(int j = 0; j < s; j++){
                int species;
                cin >> species;
                freq[species]++;
            }
        }

        int max_freq = 0;
        int second_freq = 0;

        for(auto &p : freq){
            int count = p.second;
            if(count > max_freq){
                second_freq = max_freq;
                max_freq = count;
            } else if(count > second_freq && count < max_freq){
                second_freq = count;
            }
        }

        if(second_freq == 0){
            cout << "\n";
            continue;
        }

        vector<int> answers;
        for(auto &p : freq){
            if(p.second == second_freq){
                answers.push_back(p.first);
            }
        }
        sort(answers.begin(), answers.end());

        for(int i = 0; i < (int)answers.size(); i++){
            cout << answers[i];
            if(i < (int)answers.size() - 1) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}
