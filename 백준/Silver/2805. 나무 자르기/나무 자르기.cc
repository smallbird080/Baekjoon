#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<int> trees(n,0);
    for (int i=0; i<n; i++){
        cin >> trees[i];
    }
    sort(trees.begin(), trees.end());
    int low = 0;
    int high = 1000000000;
    int pivot;
    while (low <= high){
        long long sum=0;
        pivot = (low+high+1)/2;
        for (int i=n-1; i>=0; i--){
            if (trees[i] > pivot)
                sum += (trees[i]-pivot);
            else
                break;
        }
        if (sum>=m){
            if (low==pivot)
                break;
            low = pivot;
        }
        else
            high = pivot-1;
    }
    cout << pivot;
}