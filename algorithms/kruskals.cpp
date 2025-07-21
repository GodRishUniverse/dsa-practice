#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>


using ll = long long;

using namespace std;


/*
Kruskal's algorithm

The algorithm performs the following steps:

Create a forest (a set of trees) initially consisting of a separate single-vertex tree for each vertex in the input graph.
Sort the graph edges by weight.
Loop through the edges of the graph, in ascending sorted order by their weight. For each edge:
Test whether adding the edge to the current forest would create a cycle.
If not, add the edge to the forest, combining two trees into a single tree.
At the termination of the algorithm, the forest forms a minimum spanning forest of the graph. If the graph is connected, the forest has a single component and forms a minimum spanning tree.
*/

const ll INF = 1 << 37;     // 1 << 25 acts as our infinity


struct Edge{
    ll weight, to_node; 

    bool operator>(const Edge& other) const {
        return weight > other.weight;
    }
};


// Requires the disjoint-set data structure called Union Find


void kruskals_algorithm(vector<vector<Edge>>& graph_adj_list, ll number_of_vertices){
    
}


int main(){

    
}
