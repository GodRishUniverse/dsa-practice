// A single execution of the algorithm will find the lengths (summed weights) of shortest paths between all pairs of vertices. 

// Complexity is O(v^3)

// Good exaample - https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue> 

#define ll long long

using namespace std;

const int INF = 1 << 25;     // 1 << 25 acts as our infinity

struct Edge{
    int to_node, weight;
};

vector<vector<int>> floyd_warshall(int number_of_vertices, vector<vector<Edge>> &graph_adj_list){
    vector<int> max_arr (number_of_vertices, INF);
    vector<vector<int>> dist(number_of_vertices, max_arr);
    // initialized dist to V by V grid with INF distance

    // O(E)
    for(int i =0 ; i<number_of_vertices; i++){
        for(const auto& edge: graph_adj_list[i]){
            dist[i][edge.to_node] = edge.weight;
        }
    }

    // O(V)
    for(int i =0 ; i<number_of_vertices; i++){
        dist[i][i] = 0;
    }

    // CORRECT Implementation
    // O(V^3)
    for (int k = 0 ; k < number_of_vertices; k++){
        for (int i = 0 ; i < number_of_vertices; i++){
            for (int j = 0 ; j < number_of_vertices; j++){
                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
            }
        }
    }

    return dist;
}


// test 
int main(){

    
}
