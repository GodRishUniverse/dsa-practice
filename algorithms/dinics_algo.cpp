#include <cstddef>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>

// Maximum flow problem is a optimization problem -> think about it this way you have a point s and a point t
// and you have "pipes" in different sizes called "capacities" and you want to find that given this point, what is the maximum flow of "water/something" from s to t

// This algorithm is for the maximum flow in a flow network (can be used for bipartite finding by doing janky stuff like making pseudo nodes on called s and t and ... [NEED to think about])

// General Complexity is O(V^2 * E)
// https://medium.com/smucs/understanding-dinics-algorithm-ebf892e66227



// Residual Graph -> directed graph
// We can "undo" flow here by going backward between edges

// Augmenting Path
// This is the path of edges from s to s to t, with unused capacity (>0) in the residual graph -> so pick paths that are not full as (full paths are blocked as more flow cannot happen as max cpacity is reached)
//
// flow can only go through a bottleneck value (capacity - current_flow) of >0


// Augmenting the flow
// Forward edges can be increased by the bottleneck value, while residual graph edges need to be reduced by the same amount
// these residual graph edges allow "bad" flow ("path") augmentations to be rectified as these dont give us "MAX FLOW" from s to t

// Level Graph
// basically a BFS level as you BFS from the source = s
// how far from s node


// SINCE WE DEAL WITH DIRECTED GRAPHS: LEVELS should go from LEVEL -> LEVEL+1


//The basic idea behind the algorithm is:
// Algorithm Procedure
//  1. Create the level graph by doing BFS from the source node in order to label all levels of the current flow graph
//  2. If the sink is never reached while building the level graph, stop and return the max flow
//  3. Using only valid edges in the level graph created, perform multiple DFS from the source node to the sink node until a blocking flow is reached, and sum up the bottleneck values of all the augmenting paths that were found to calculate the max flow

// Blocking flow — A flow is blocking flow if there is no more flow that can be sent through an edge using the level graph.

using ll = long long;
using namespace std;

const ll INF = 1 << 31;


struct FlowEdge{
    ll to_node, capacity, flow =0;
};

bool bfs(vector<vector<FlowEdge>>& graph,ll s, ll t ){
    vector<ll> level(graph.size(), -1);
    level[s] =0;

    queue<ll> q;
    q.push(s);

    while (!q.empty()){
        ll v = q.front(); q.pop();
        for (const FlowEdge& edge : graph[v]){
            if (level[edge.to_node]<0 && edge.flow < edge.capacity){
                level[edge.to_node] = level[v]+1;
                q.push(edge.to_node);
            }
        }
    }

    return (level[t] >= 0); // we did not find level[t] if less than 0
}

void dinics(vector<vector<FlowEdge>>& graph, ll s, ll t ){

}

using namespace std;
int main(){

}
