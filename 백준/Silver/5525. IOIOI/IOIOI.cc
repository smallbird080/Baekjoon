#include <iostream>
#include <string>

int main(){
    int n,m,cnt = 0;
    std::string s;
    std::cin>>n>>m>>s;
    int index = 0;
    while (index<m){
        int numOI = 0;
        if (s[index] == 'I'){
            while (s[index+1]=='O' && s[index+2]=='I'){
                numOI++;
                index +=2;
                if(numOI==n){
                    cnt++;
                    numOI--;
                }
            }
        }
        index++;
    }
    std::cout<<cnt;
}