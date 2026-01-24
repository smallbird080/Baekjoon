#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define IO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

long ccw(pair<long, long> a, pair<long, long> b, pair<long, long> c){
    return (a.first*b.second + b.first*c.second + c.first*a.second) - (a.second*b.first + b.second*c.first + c.second*a.first);
}

int main() {
    IO;
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (int i=0; i<n; i++){
        cin >> points[i].first >> points[i].second;
    }
    double result = 0;
    for (int i=0; i<n-2; i++){
        result += ccw(points[0], points[i+1], points[i+2]) / (double)2;
    }
    result = abs(result);
    cout << fixed;
    cout.precision(1);
    cout << result;
}
