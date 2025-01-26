#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    int k,n,a,score,rounds=0;
    bool newRound = true;
    cin >> k >> n;
    while (k--){
        if (newRound){
            newRound = false;
            score = n;
        }
        cin >> a;
        score = score-a<0 ? score : score-a;
        if (!score){
            newRound = true;
            rounds++;
        }
    }
    cout << rounds << "\n" << score;
}