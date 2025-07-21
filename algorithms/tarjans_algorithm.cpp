#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iostream>
#include <set>

using ll = long long;
using namespace std;


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

void printSCCs(vector<vector<ll>>& scc_list){
    for (vector<ll>& v: scc_list){
        cerr << "SCC : ";
        for (ll& c : v) cerr << c <<", ";
        cerr << endl;
    }

}


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

    printSCCs(scc_list);

    return scc_list;
}




int main(){

    vector<vector<Edge>> graph {{{1,1} } , {{1,6}, {1,4} , {1,2}}, {{1,3}}, {{1,2}, {1,4}, {1,5}}, {{1,5}}, {{1,4}}, {{1,0}, {1,2}}  };
    vector<vector<ll>> scc = tarjans_algorithm(graph);


    
}
