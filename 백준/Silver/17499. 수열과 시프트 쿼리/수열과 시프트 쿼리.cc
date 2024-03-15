#include <iostream>

using namespace std;

int main(){
    int n,q,x,index, task;
    cin>>n>>q;
    long a;
    long arr[200002] = {-1};
    for (int i=0; i<n; i++){
        cin>>a;
        arr[i] = a;
    }
    int s = 0;
    for (int i=0; i<q; i++){
        cin>>task;
        switch (task)
        {
        case 1:
            cin>>index>>x;
            arr[(index-1+s)%n] += x;
            break;
        case 2:
            cin>>x;
            s = (s-x+n)%n;
            break;
        case 3:
            cin>>x;
            s = (s+x)%n;
            break;
        default:
            break;
        }
    }
    for (int i=0; i<n; i++){
        cout<<arr[(i+s)%n]<<" ";
    }
}