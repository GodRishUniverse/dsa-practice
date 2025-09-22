#include <iostream>
#include <vector>


using ll = long long;


using namespace std;

struct Edge{
  ll to_node, weight;
};

bool hasPath(vector<vector<Edge>>& graph, int src, int dest){
    // run a dfs on this
    vector<int> st;
    st.push_back(src);
    vector<bool> visited(graph.size(), false);

    while (!st.empty()){
        ll v = st[st.size()-1]; st.pop_back();
        if (!visited[v]){
            visited[v] = true;
            for (Edge& e: graph[v]){
                if (e.to_node == dest) return true;
                st.push_back(e.to_node);
            }
        }
    }
    return false;
}

int main(){

    vector<vector<Edge>> graph {{{1,0}, {2,0}}, {{2,0}}, {{0,0}, {3,0}}, {{3,0}}};
    int u = 3, v =1;
    if (hasPath(graph, u,v)){
        cout << "\n There is a path from " << u << " to " << v << endl;
    }else{
        cout << "\n There is no path from " << u << " to " << v << endl;
    }

}
