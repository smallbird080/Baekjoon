#include <iostream>
#include <queue>

using namespace std;

struct number
{
    int num;
    int cnt;
};


int main() {
    int cnt = 0;
    int num;
    cin >> num;
    if (num==1){
        cout << 0;
        return 0;
    }
    queue<number> q;
    q.push({num,cnt});
    while (!q.empty())
    {   
        number element = q.front();
        int target = element.num;
        int result;
        q.pop();
        if (!(target%3)) {
            result = target/3;
            if (result == 1){
                cnt = element.cnt;
                break;
            }
            q.push({result,element.cnt+1});
        } 
        if (!(target%2)) {
            result = target/2;
            if (result == 1){
                cnt = element.cnt;
                break;
            }
            q.push({result,element.cnt+1});
        }
        result = target-1;
        if (result == 1){
                cnt = element.cnt;
                break;
            }
        q.push({result,element.cnt+1});
        

    }
    
    cout << cnt+1 << endl;
}