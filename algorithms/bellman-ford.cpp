
/*
Bellman-Ford is a single source shortest path algorithm. 
It effectively works in the cases of negative edges and is able to 
detect negative cycles as well.
It works on the principle of relaxation of the edges.
*/

// A point of difference with Djikstra's is also that this is NOT GREEDY

// Time complexity is O(V \times E)

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue> 

using ll = long long;

using namespace std;

const int INF = 1 << 25;     // 1 << 25 acts as our infinity

struct Edge{
    int to_node, weight; 
};

vector<int> bellman_ford(int number_of_vertices,vector<vector<Edge>> &graph_adj_list, int source ){
    vector<int> dist(number_of_vertices, INF);
    dist[source] =0; 

    // V-1 relaxations for each edge
    for (int i = 0; i <number_of_vertices; ++i){
       // traverse each edge - we are assuming directed graph - for undirected this will be 2 times the number of edges
       for (size_t node = 0 ; node<graph_adj_list.size(); node++){
         for (const auto& edge: graph_adj_list[node]){
            if (dist[node] != INF && dist[node] + edge.weight < dist[edge.to_node]) {
                // If this is the Vth relaxation, then there is
                // a negative cycle
                if(i == number_of_vertices - 1)
                    return {-1}; // return -1 for negative cycle as minimum path not possible
               
                // Update shortest distance to node 
                dist[edge.to_node] = dist[node] + edge.weight;
            }
         }
       }
    }

    return dist;
}

// for testing
int main(){
    int V = 5;

    Edge zro{1,5};

    Edge one{3,2};
    Edge two{2, 1};

    Edge three{4,1};

    Edge four{3,-1};

    vector<vector<Edge>> graph(V);

    graph[0] = {zro};
    graph[1] = {one,two};
    graph[2] = {three};
    graph[4] = {four};

    vector<int> distances = bellman_ford(V, graph,0);

    for (size_t i =0; i < distances.size(); i++){
        cout << i << " : " << distances[i] << endl;
    }
    
}
