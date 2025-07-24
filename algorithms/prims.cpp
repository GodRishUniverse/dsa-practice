#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using ll = long long;

using namespace std;


// Prim's algorithm is a greedy algorithm to get a Minimum spanning tree from a graph
/*

The algorithm starts with an empty spanning tree and the we maintain two sets of vertices:
    - one contains the vertices already included in the MST
    - the other set contains the vertices not yet included.
At every step, it considers all the edges that connect the two sets and picks the minimum weight edge from these edges.
After picking the edge, it moves the other endpoint of the edge to the set containing MST. 
*/

const ll INF = 1 << 37;     // 1 << 25 acts as our infinity


struct Edge{
    ll weight, to_node; 

    bool operator>(const Edge& other) const {
        return weight > other.weight;
    }
};

// already using an adjacency list representation
vector<Edge> prims_algorithm(vector<vector<Edge>> &graph_adj_list, ll number_of_vertices){
    vector<ll> cheapestCost(number_of_vertices, INF);
    vector<ll> parent(number_of_vertices, -1);  // Track parent for MST construction
    
    vector<bool> explored(number_of_vertices, false);  // More efficient than set
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    ll source = 0;
    cheapestCost[source] = 0;
    pq.push({0, source});

    vector<Edge> mst_edges;  // Store MST edges directly

    while (!pq.empty()) {
        auto [currCost, currVertex] = pq.top();  pq.pop();
        
        // Skip if already processed
        if (explored[currVertex]) {
            continue;
        }

        explored[currVertex] = true;
        
        // Add edge to MST (except for source)
        if (parent[currVertex] != -1) {
            mst_edges.push_back({currCost, parent[currVertex]});  // or however you want to represent the edge
        }

        // Process all neighbors
        for (const Edge& edge : graph_adj_list[currVertex]) {
            ll neighbor = edge.to_node;
            ll weight = edge.weight;
            
            if (!explored[neighbor] && weight < cheapestCost[neighbor]) {
                cheapestCost[neighbor] = weight;
                parent[neighbor] = currVertex;
                pq.push({weight, neighbor});
            }
        }
    }

    return mst_edges;
}


int main(){

}
