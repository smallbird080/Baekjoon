#include <iostream>

using namespace std;

const int TOTAL_CASES = 2*500000;
bool broken[10];

bool isCaseBroken(int n){
    if(n==0){
        if (broken[0])
            return true;
        else
            return false;
    }
    while (n>0){
        if(broken[n%10])
            return true;
        n /= 10;
    }
    return false;
}

int main(){
    int n,m,b;
    cin>>n>>m;
    for (int i=0; i<10; i++)
        broken[i] = false;
    for (int i=0;i<m;i++){
        cin>>b;
        broken[b] = true;
    }
    int result = abs(n-100);
    for (int i=0;i<TOTAL_CASES; i++){
        int len = to_string(i).length();
        if(!isCaseBroken(i)){
            if(result > len+abs(n-i))
                result = len+abs(n-i);
        }
    }
    cout<<result;

}