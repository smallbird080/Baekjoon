#include <iostream>
#include <set>
#include <stack>

using namespace std;

bool isVar(char c){
    set<char> ops({'*','+','-','/','(',')'});
    return ops.find(c) == ops.end();
}

bool isLower(char op1, char op2){
    if (op1=='(')
        return true;
    if (op2=='+' || op2=='-')
        return false;
    if ((op1=='+' || op1=='-') && (op2=='*' || op2=='/'))
        return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    string in;
    cin >> in;
    stack<char> ops;
    for (char v : in){
        if (isVar(v)){
            cout << v;
        }
        else if (v=='('){
            ops.push(v);
        }
        else if (v==')'){
            while (ops.top() != '('){
                cout << ops.top();
                ops.pop();
            }
            ops.pop();
        }
        else if (ops.empty()){
            ops.push(v);
        }
        else{
            while (!ops.empty() && !isLower(ops.top(),v)){
                cout << ops.top();
                ops.pop();
            }
            ops.push(v);
        }
    }
    while (!ops.empty()){
        cout << ops.top();
        ops.pop();
    }
}