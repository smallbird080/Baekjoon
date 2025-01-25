#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n,r,l,s,me,mn;
    scanf("%d", &n);
    unordered_map<int,int> cure;
    for (int i=0; i<n; i++){
        scanf("%d %d",&me, &mn);
        cure[me] = mn;
    }
    
    scanf("%d", &r);
    while (r--){
        vector<int> S(0);
        bool dead = false;
        scanf("%d", &l);
        while (l--){
            scanf("%d", &s);
            if (!cure.count(s))
                dead = true;
            else
                S.push_back(s);
        }
        if (dead){
            printf("YOU DIED");
        }
        else{
            for (int symp : S)
                printf("%d ",cure[symp]);
        }
        printf("\n");
    }
}