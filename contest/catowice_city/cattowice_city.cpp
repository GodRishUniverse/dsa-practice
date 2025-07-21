#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iostream>
#include <set>

using ll = long long;
using namespace std;

// TODO: TLE's on test case 4

// Graph is represented as an adjacency list

struct Edge{
    ll weight, to_node;
};


void strong_connect(vector<vector<Edge>>& graph, ll v, stack<ll>& S, vector<bool>& on_stack, vector<ll>& indices, vector<ll>& lowlink, ll& index, vector<vector<ll>>& scc_list){
    indices[v] = index;
    lowlink[v] = index;
    index++;
    S.push(v);
    on_stack[v] = true;

    // all successors of V
    for (Edge e : graph[v]){
        if (indices[e.to_node]==-1){
            // successor has not been visited yet
            strong_connect(graph, e.to_node, S, on_stack, indices, lowlink, index, scc_list);
            lowlink[v] = min(lowlink[v], lowlink[e.to_node]);
        } else if (on_stack[e.to_node]){
            // Successor already on the stack and so is in the same SCC
            lowlink[v] = min(lowlink[v], indices[e.to_node]);
        }
    }

    // root of the scc graph - chosen to be the lowlink value
    if (lowlink[v] == indices[v]){
        vector<ll> scc;
        ll w;
        do {
            w = S.top(); 
            S.pop();
            on_stack[w] = false;
            scc.push_back(w);
        } while (w != v);  // Stop when we reach the root of this SCC
        scc_list.push_back(scc);

        return; // terminate
    }

}

// void printSCCs(vector<vector<ll>>& scc_list){
//     for (vector<ll>& v: scc_list){
//         cerr << "SCC : ";
//         for (ll& c : v) cerr << c <<", ";
//         cerr << endl;
//     }

// }


vector<vector<ll>> tarjans_algorithm(vector<vector<Edge>>& graph){
    vector<ll> indices(graph.size(), -1);
    vector<ll> lowlink(graph.size(), -1);
    vector<bool> onStack(graph.size(), false);

    ll index {0};

    stack<ll> S;

    vector<vector<ll>> scc_list;

    for (size_t v =0; v<graph.size(); v++){
        if (indices[v]==-1){
            strong_connect(graph, v, S, onStack, indices, lowlink, index, scc_list);
        }
    }

    // printSCCs(scc_list);

    return scc_list;
}


int main(){
    ll tests;
    cin >> tests;

    while(tests--){
        ll n , m;
        cin >> n >> m;
        vector<vector<Edge>> graph(n);
        while (m--){
            ll a , b;
            cin >> a >> b;
            graph[a-1].push_back({-1, b-1});
        }

        vector<vector<ll>> scc = tarjans_algorithm(graph);
        if (scc.size() <2){
            cout << "NO" <<endl;
        }else{
            cout << "YES" <<endl;
            cout << scc[0].size() << " " << n-scc[0].size() <<endl;
            for (size_t i =0; i <scc[0].size(); i++){
                if (i==scc[0].size()-1){
                    cout << scc[0][i]+1 << endl;
                }else{
                    cout << scc[0][i]+1 << " ";
                }
            }

            for (size_t j =1; j < scc.size(); j ++){
                for (size_t i =0; i <scc[j].size(); i++){
                    if (i==scc[j].size()-1 && j == scc.size()-1){
                        cout << scc[j][i]+1 << endl;
                    }else{
                        cout << scc[j][i]+1 << " ";
                    }
                }
            }
        }
    }

}
