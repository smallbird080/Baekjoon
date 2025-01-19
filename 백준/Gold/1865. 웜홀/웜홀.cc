#include <iostream>
#include <vector>
#define MAX 999999

using namespace std;


struct Edge{
    int from;
    int to;
    int weight;
    Edge(){
        from = -1;
        to = -1;
        weight = MAX;
    }
    Edge(int from, int to, int w){
        this->from = from;
        this->to = to;
        this->weight = w;
    }
};

void relax(const vector<Edge>& e, vector<int>& v, int n);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc,s,e,t;
    cin >> tc;
    while (tc--){
        int n,m,w;
        cin >> n >> m >> w;
        vector<Edge> edges;
        vector<int> vertex(n,0);
        while (m--){
            cin >> s >> e >> t;
            edges.push_back(Edge(s-1,e-1,t));
            edges.push_back(Edge(e-1,s-1,t));
        }
        while (w--){
            cin >> s >> e >> t;
            edges.push_back(Edge(s-1,e-1,t*(-1)));
        }
        bool neg = false;
        for (int j=0; j<n-1; j++)
            relax(edges,vertex,n);
        for (Edge e : edges){
            if (vertex[e.to] > vertex[e.from] + e.weight){
                neg = true;
                break;
            }
        }
        if (neg)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}

void relax(const vector<Edge>& edges, vector<int>& v, int n){
    for (Edge e : edges){
        v[e.to] = min(v[e.to],v[e.from] + e.weight);
    }
}