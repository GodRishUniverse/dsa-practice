#include <vector>
#include <iostream>
#include <stack>
#include <exception>

using ll = long long;

using namespace std;

struct Edge{
    ll weight, to_node;
};


// TOPOLOGICAL SORT ONLY WORKS FOR DAGs - does not work for graphs with cycles and undirected graphs

//TODO: implement a topological sort for a particular node - make sure to assume that NODE Has zero in-degree

 
vector<ll> toposort(vector<vector<Edge>>& graph){
    // let us find a node with 0 in-degree - need to check all edges as we have adjacency list for to_nodes
    vector<ll> in_degrees_of_nodes(graph.size(), 0);
    for (size_t i =0; i<graph.size(); i++){
        for (Edge& e : graph[i]){
            in_degrees_of_nodes[e.to_node]++;
        }
    }
    
    // gets the first node with 0 in-degree
    vector<ll> toposort_nodes;
    for (size_t i =0; i<in_degrees_of_nodes.size(); i++){
        if (in_degrees_of_nodes[i]==0){
            toposort_nodes.push_back(i);
            
        }
    }

    vector<ll> topological_ord;
    while (!toposort_nodes.empty()){
        ll node = toposort_nodes[toposort_nodes.size()-1];toposort_nodes.pop_back();
        topological_ord.push_back(node);
        for (Edge& e: graph[node]){
            in_degrees_of_nodes[e.to_node]--;
            if (in_degrees_of_nodes[e.to_node]==0){
                toposort_nodes.push_back(e.to_node);
            }
        }
    }

    if (topological_ord.size() != graph.size()){
        // graph has a cycle
        throw exception();
    }

    return topological_ord;
}



int main(){
    vector<vector<Edge>> graph {{{1,1},{1,2}}, {{1,2},{1,3}}, {{1,4}}, {{1,2}, {1,4}}, {}};

    vector<ll> order =  toposort(graph);
    for (ll o: order) cout << "VERTEX: " << o << endl;

}
