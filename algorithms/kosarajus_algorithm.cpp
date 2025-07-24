#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

using ll = long long;
using namespace std;


struct Edge{
    ll weight, to_node;
};


void Visit(vector<vector<Edge>>& graph, ll v,  stack<ll>& L, vector<bool>& visited){
    if (!visited[v]){
        visited[v] = true;
        for (Edge& e : graph[v]){
            Visit(graph, e.to_node,  L, visited);
        }
        L.push(v);
    }
}

void Assign(vector<vector<Edge>>& graph, ll u , ll root, vector<ll>& assigned_component_root, vector<vector<ll>>& components){
    if (assigned_component_root[u] == -1){
        assigned_component_root[u] = root;
        components[root].push_back(u);

        for (ll& in_neighbour : in_neighbours){
            Assign(graph, in_neighbour, root, assigned_component_root, components);
        }
    }
}

void printSCCs(vector<vector<ll>>& scc_list){
    for (vector<ll>& v: scc_list){
        cerr << "SCC : ";
        for (ll& c : v) cerr << c <<", ";
        cerr << endl;
    }

}

vector<vector<ll>> kosaraju(vector<vector<Edge>>& graph ){
    vector<bool> visited (graph.size(), false);
    vector<ll> assigned_component (graph.size(), -1);
    stack<ll> L;


    vector<vector<ll>> in_neighbours;
    for (size_t v = 0; v <graph.size(); v++){
        for (Edge& e : graph[v]){
            if (e.to_node == u){
                in_neighbours[u].push_back(v);
            }
        }
    }

    for (size_t v = 0; v <graph.size(); v++){
        Visit(graph, v, L, visited);
    }

    vector<vector<ll>> components(graph.size());
    vector<vector<ll>> actual;

    while (!L.empty()){
        ll u = L.top(); L.pop();
        Assign(graph, u, u, assigned_component, components);
    }

    for (vector<ll>& vec : components ){
        if (!vec.empty()){
            actual.push_back(vec);
        }
    }

    printSCCs(actual);

    return actual;
}


int main(){
    
    vector<vector<Edge>> graph {{{1,1} } , {{1,6}, {1,4} , {1,2}}, {{1,3}}, {{1,2}, {1,4}, {1,5}}, {{1,5}}, {{1,4}}, {{1,0}, {1,2}}  };
    vector<vector<ll>> scc = kosaraju(graph);

}
