#include <iostream>
#include <vector>
#include <stack>

#define IO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

enum state {LOOP, NOT_LOOP, VISITED, FRESH};

int main() {
    IO;
    int t,n;
    cin >> t;
    for (int k=0; k<t; k++){
        cin >> n;
        vector<int> point(n+1);
        vector<state> visited(n+1,FRESH);
        stack<int> loop;
        int bocchi = n;
        for (int i=1; i<=n; i++)
            cin >> point[i];
        
        for (int i=1; i<=n; i++){
            if (visited[i] != FRESH)
                continue;
            
            loop.push(i);
            while (!loop.empty()){
                int cur = loop.top();
                visited[cur] = VISITED;
                int next = point[cur];
                if (visited[next] == VISITED){
                    while (loop.top() != next){
                        visited[loop.top()] = LOOP;
                        bocchi--;
                        loop.pop();
                    }
                    visited[next] = LOOP;
                    bocchi--;
                    break;
                }
                if (visited[next] != FRESH)
                    break;
                loop.push(next);
            }
            while (!loop.empty()){
                int cur = loop.top();
                visited[cur] = NOT_LOOP;
                loop.pop();
            }
        }
        cout << bocchi << '\n';
    }
}
