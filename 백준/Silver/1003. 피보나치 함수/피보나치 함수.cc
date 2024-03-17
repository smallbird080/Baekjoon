#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int fibo1(int n){
    int a0 = 0;
    int a1 = 1;
    int result = 0;
    for (int i=0; i<n; i++){
        result = a0+a1;
        a0 = a1;
        a1 = result;
    }
    return result;
}

int fibo0(int n){
    int a0 = 1;
    int a1 = 0;
    int result = 0;
    for (int i=0; i<n; i++){
        result = a0+a1;
        a0 = a1;
        a1 = result;
    }
    return result;
}

int main(){
    int t,n;
    cin>>t;
    for(int i=0; i<t ; i++){
        cin>>n;
        switch (n)
        {
        case 0:
            cout<<"1 0"<<endl;
            break;
        case 1:
            cout<<"0 1"<<endl;
            break;
        
        default:
            cout<<fibo0(n-1)<<" "<<fibo1(n-1)<<endl;
            break;
        }
    }
}