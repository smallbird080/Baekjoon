#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define IO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

struct DisjSet{
    vector<int> arr;

    DisjSet(int size){
        arr = vector<int>(size,-1);
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
        }
        else{
            if (arr[x]==arr[y])
                (arr[y])--;
            arr[x] = y;
        }
        return true;
    }
};

int main(){
    IO;
    int n, m;
    cin >> n >> m;
    DisjSet points(n);

    int result = 0;
    for (int i=1; i<=m; i++){
        int u,v;
        cin >> u >> v;
        if (!points.uni(points.find(u),points.find(v))){
            result = i;
            break;
        }
    }

    cout << result;
}