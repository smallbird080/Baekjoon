#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>


using namespace std;

bool CHECKED = true;

int D(int num){
    num *= 2;
    if (num > 9999)
        num %= 10000;
    return num;
}
int S(int num){
    num -= 1;
    if (num <0)
        num = 9999;
    return num;
}
int L(int num){
    num = (num % 1000) * 10 + num/1000;
    return num;
}
int R(int num){
    num = (num % 10) * 1000 + num/10;
    return num;
}

string calculate(){
    bool checkNode[10000];
    for (int i=0 ;i<10000; i++)
        checkNode[i] = false;
    
    queue<pair<int,string>> q;
    int A,B;
    cin>>A>>B;
    q.push(make_pair(A,""));
    checkNode[A] = CHECKED;
    while (!q.empty()){
        int currentNum = q.front().first;
        string history = q.front().second;
        q.pop();
        if(currentNum == B){
            return history;
        }
        int temp;
        temp = D(currentNum);
        if(checkNode[temp] != CHECKED){
            q.push(make_pair(temp,history+"D"));
            checkNode[temp] = CHECKED;
        }
        temp = S(currentNum);
        if(checkNode[temp] != CHECKED){
            q.push(make_pair(temp,history+"S"));
            checkNode[temp] = CHECKED;
        }
        temp = L(currentNum);
        if(checkNode[temp] != CHECKED){
            q.push(make_pair(temp,history+"L"));
            checkNode[temp] = CHECKED;
        }
        temp = R(currentNum);
        if(checkNode[temp] != CHECKED){
            q.push(make_pair(temp,history+"R"));
            checkNode[temp] = CHECKED;
        }
    }
    return "";
}

int main(){
    int numCals;
    cin>>numCals;
    for (int i=0; i<numCals; i++){
        cout<<calculate()<<endl;
    }
}