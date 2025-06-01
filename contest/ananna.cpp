#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <stack>
#include <algorithm> 
#include <deque>
#include <utility>


#define ll long long

using namespace std;

struct Edge{
    ll othernode;
    string edgeLabel;
};

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> incoming(n+1);
    vector<vector<Edge>> outgoing(n+1);

    deque<pair<ll,ll>> edge;

    vector<vector<bool>> visited(n+1, vector<bool>(n+1, false));


    ll count {};


    for (int i =0 ; i < m; i++){
        ll u,v;
        string val;

        cin >> u >> v >> val;

        edge.push_back({u,v});
        incoming[v].push_back({u, val});
        outgoing[u].push_back({v,val});

        if (!visited[u][v]) {
            visited[u][v] = true;
            edge.emplace_back(u, v);
            if (u != v) {
                count++;
            }
        }
    }

    for(int u = 1; u <= n; u++) {
        if (!visited[u][u]) {
            visited[u][u] = true;
            edge.emplace_back(u, u);
        }
    }


    while(!edge.empty()){
        auto [u, v] = edge.front(); edge.pop_front();
        for(const auto& a : incoming[u]){
            ll a_node   = a.othernode;
            const string &c1 = a.edgeLabel;
            for (const auto& b: outgoing[v]){
                ll b_node   = b.othernode;
                const string &c2 = b.edgeLabel;

                if (!visited[a_node][b_node]) {
                        visited[a_node][b_node] = true;
                        edge.emplace_back((int)a_node, (int)b_node);
                        if (a_node != b_node) {
                            count++;
                        }
                }
            }
        }
    }

    cout << count << endl;
}
