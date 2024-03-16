#include <iostream>
#include <cmath>

using namespace std;

int R,C;

long Z(int n){
    if(n==1){
        return 2*R+C;
    }
    if(R<pow(2,n-1) && C<pow(2,n-1)){ // 0
        return Z(n-1);
    }
    if(R<pow(2,n-1) && C>=pow(2,n-1)){ // 1
        C -= pow(2,n-1);
        return pow(4,n-1)+Z(n-1);
    }
    if(R>=pow(2,n-1) && C<pow(2,n-1)){ // 2
        R -= pow(2,n-1);
        return 2*pow(4,n-1)+Z(n-1);
    }
    if(R>=pow(2,n-1) && C>=pow(2,n-1)){ // 3
        C -= pow(2,n-1);
        R -= pow(2,n-1);
        return 3*pow(4,n-1)+Z(n-1);
    }
}

int main(){
    int N;
    cin>>N>>R>>C;
    cout<<Z(N);
}