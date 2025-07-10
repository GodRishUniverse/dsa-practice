#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <iostream>

#define ll long long 

using namespace std;

const ll INF = 1 <<38;
using Edge = pair<ll,ll>;

// find the shortest path from 1 to n

pair<vector<ll>, vector<ll>> djikstra(const vector<vector<Edge>> &graph, ll n){
    
    vector<ll> prevs(n+1, INF);
    vector<ll> dist(n+1, INF);

    dist[1] = 0;
    prevs[1] = 0;


    priority_queue<Edge, vector<Edge> ,greater<Edge>> heap;
    
    heap.emplace(0, 1);

    while (!heap.empty()){
        auto [ curr_dist, node] = heap.top(); heap.pop();

        if (curr_dist > dist[node]) continue; 

        for (auto [v, d] : graph[node]){
            if (dist[v] > dist[node] + d){
                dist[v] = dist[node] + d;
                prevs[v] = node;
                heap.emplace(dist[v],v);
            }
        }
    }

    return {dist, prevs};

}

int main(){
    int n,m;
    cin >> n >>m ;
        
    // get the graph
    vector<Edge> temp;
    vector<vector<Edge>> graph(n+1, temp);
    int from, to, weight;

    for (size_t i = 0; i < m; i++){
        
        cin >>  from >> to >> weight;
        // undirected
        graph[from].push_back({to, weight});
        graph[to].push_back({from, weight});
    }
    

    auto [dists, prevs] = djikstra(graph, n );

    // // Distances
    // cout << "DISTS" << endl;
    // for (size_t i =0 ; i< dists.size(); i++){
    //     cout << i << " : " <<  dists[i] << " " << endl;
    // }

    // // Prevs
    // cout << "PREVS" << endl;
    // for (size_t i =0 ; i< prevs.size(); i++){
    //     cout << i << " : " <<  prevs[i] << " " << endl;
    // }

    // TODO: FAILS test 31
    vector<ll> pathway;
    int current = n;
    pathway.push_back(n);
    while (current != INF && prevs[current] != 0){
        pathway.push_back(prevs[current]);
        current = prevs[current];
    }

    // NO PATHWAY
    if(prevs[n] == INF || pathway[pathway.size()-1] != 1){
        cout << -1 << endl;
    }else{
        auto iter = pathway.crbegin();
        while (iter != pathway.crend()){
            cout << *iter << " ";
            ++iter;
        }
    }
}
