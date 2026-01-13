#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define IO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

int main() {
    IO;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i=0; i<n; i++)
        cin >> nums[i];

    int cnt = 0;
    for (int num : nums){
        bool isprime = true;
        if (num == 1)
            continue;
        if (num == 2){
            cnt++;
            continue;
        }
        int sqr = (int)sqrt(num) + 1;
        for (int i=2; i<=sqr; i++){
            if (num % i == 0){
                isprime = false;
                continue;
            }
        }
        if (isprime)
            cnt++;
    }
    cout << cnt;
}