#include <iostream>
#include <string>

std::string getPattern(int n){
    std::string base = "IOI";
    for (int i=1; i<n; i++){
        base = base+"OI";
    }
    return base;
}



int main(){
    int n,m,cnt = 0;
    std::string s;
    std::cin>>n>>m>>s;
    std::string pattern = getPattern(n);
    int index = 0;
    while (index<m){
        if (s[index] == 'I'){
            int i = 0;
            int tempIndex = index;
            while(i<(int)(pattern.size()) && s[tempIndex] == pattern[i]){
                i++;
                tempIndex++;
            }
            if(i==(int)(pattern.size())){
                index +=2;
                cnt++;
                continue;
            }
            else{
                index = tempIndex;
                continue;
            }

        }
        else{
            index++;
            continue;
        }
    }
    std::cout<<cnt;
}