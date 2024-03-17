#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n,time;
    vector<int> p;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>time;
        p.push_back(time);
    }
    sort(p.begin(), p.end());
    int sum = 0;
    for (int i=0;i<n;i++){
        for (int j=0; j<=i; j++){
            sum += p[j];
        }
    }
    cout<<sum;
}