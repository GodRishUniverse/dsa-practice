// Djikstra's only works on non-negative weight  edges and needs a source

// THIS IS A GREEDY ALGORITHM

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


vector<int> djikstras(int number_of_vertices, vector<vector<Edge>> &graph_adj_list, int source){

    // Min heap - default priority queue is max heap
     using Node = pair<int,int>; 
    priority_queue<Node, vector<Node>, 
                   greater<Node>> heap;
    
    vector<int> dist(number_of_vertices, INF);

    dist[source] = 0;
    heap.emplace(0, source);
    
    while( !heap.empty()){
        auto [d, vertex] = heap.top(); heap.pop();

        if (d != dist[vertex]) continue;  
        
        for (const auto &u: graph_adj_list[vertex] ){

            if (dist[u.to_node] > d + u.weight){
                dist[u.to_node] = d +u.weight;
                heap.emplace(dist[u.to_node], u.to_node);
            }
        }
    }

    return dist;
}


int main(){
    // test

    /*
    
    0 ---w=2---1
    |  w=1-----/
   w=7 /
    | /
    2----w=4----3
    
    */

    // directed graph

    Edge first{1,2};
    Edge second{2, 7};

    Edge third{2, 1};
    Edge forth{3, 4};


    vector<vector<Edge>> graph(4);   // 0-3 inclusive
    graph[0] = {first, second};
    graph[1] = {third};
    graph[2] = {forth};

    vector<int> distances = djikstras(4, graph, 0);

    for (size_t i =0 ; i <distances.size(); ++i){
        cout << i << " : " << distances[i] << endl;
    }

    // another test
    


}
