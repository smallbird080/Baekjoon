#include <iostream>
#include <vector>
#include <array>

#define IO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;


struct DisjSet{
    vector<int> arr;
    vector<int> size;
    
    DisjSet(int length){
        arr = vector<int>(length,-1);
        size = vector<int>(length,1);
    }
    
    int find(int x){
        if (arr[x] < 0)
        return x;
        else{
            arr[x] = find(arr[x]);
            return arr[x];
        }
    }
    
    bool uni(int x, int y){
        if (x == y){
            return false;
        }
        if (arr[x] < arr[y]){
            arr[y] = x;
            size[x] += size[y];
        }
        else{
            if (arr[x]==arr[y])
            (arr[y])--;
            arr[x] = y;
            size[y] += size[x];
        }
        return true;
    }
};

int ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
    long long res = (x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3);
    if (res > 0) return 1;
    if (res < 0) return -1;
    return 0;
}

bool checkCrossing(array<int, 4>& line1, array<int, 4>& line2) {
    pair<long long, long long> p1 = {line1[0], line1[1]};
    pair<long long, long long> p2 = {line1[2], line1[3]};
    pair<long long, long long> p3 = {line2[0], line2[1]};
    pair<long long, long long> p4 = {line2[2], line2[3]};

    int ABC = ccw(p1.first, p1.second, p2.first, p2.second, p3.first, p3.second);
    int ABD = ccw(p1.first, p1.second, p2.first, p2.second, p4.first, p4.second);
    int CDA = ccw(p3.first, p3.second, p4.first, p4.second, p1.first, p1.second);
    int CDB = ccw(p3.first, p3.second, p4.first, p4.second, p2.first, p2.second);

    if (ABC * ABD <= 0 && CDA * CDB <= 0) {
        if (ABC == 0 && ABD == 0 && CDA == 0 && CDB == 0) {
            if (p1 > p2) swap(p1, p2);
            if (p3 > p4) swap(p3, p4);
            return p3 <= p2 && p1 <= p4;
        }
        return true;
    }
    return false;
}

int main() {
    IO;
    int n;
    cin >> n;
    vector<array<int,4>> lines(n);
    DisjSet ds(n);
    for (int i=0; i<n; i++){
        cin >> lines[i][0] >> lines[i][1] >> lines[i][2] >> lines[i][3];
    }

    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            bool crossing = checkCrossing(lines[i], lines[j]);
            if (crossing){
                ds.uni(ds.find(i),ds.find(j));
            }
        }
    }
    for (int i=0; i<n; i++){
        ds.find(i);
    }
    int maxSize = 0;
    int numGroup = 0;
    for (int i=0; i<n; i++){
        if (ds.arr[i] < 0){
            numGroup++;
            maxSize = max(maxSize, ds.size[i]);
        }
    }
    cout << numGroup << '\n' << maxSize;
}
