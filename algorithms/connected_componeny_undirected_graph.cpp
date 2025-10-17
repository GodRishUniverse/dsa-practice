#include <iostream>
#include <vector>

using ll = long long;

using namespace std;

struct Edge{
    ll to_node, weight;
};

vector<ll> dfs(ll node, vector<bool>& visited, vector<vector<Edge>>& graph){
    vector<ll> res;
    vector<ll> st;
    st.push_back(node);

    while(!st.empty()){
        ll u = st[st.size()-1]; st.pop_back();
        if (!visited[u]){
            visited[u] = true;
            res.push_back(u);
            for (Edge& e: graph[u]){
                st.push_back(e.to_node);
            }
        }
    }

    return res;
}


vector<vector<ll>> getConnectComponents(vector<vector<Edge>>& graph){
    vector<bool> visited(graph.size()+1, false);
    vector<vector<ll>> connected_comps;
    for (ll node =0; node<graph.size(); node++){
        if (!visited[node]){
            // dfs on the node
            // add to connected_comps
            vector<ll> cc = dfs(node, visited,graph);
            connected_comps.push_back(cc);
        }
    }

    return connected_comps;
}

int main(){

    vector<vector<Edge>> graph = {{{1,0}}, {{0,0}}, {}, {{5,0}}, {{5,0}}, {{3,0}, {4,0}, {6,0}, {7,0}}, {{5,0}}, {{5,0}}};

    cout << getConnectComponents(graph).size() << endl;
}
