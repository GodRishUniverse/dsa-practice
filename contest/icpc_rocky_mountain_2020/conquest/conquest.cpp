#include <cstddef>
#include <iostream>
#include <vector>
#include <set>
#include <queue>

using ll = long long;
using namespace  std;

// struct Edge{
//   ll to_node;
// };


int main(){
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> graph(n,vector<ll>());
    vector<ll> army (n, 0);
    while(m--){
        ll u,v;
        cin >> u >> v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }

    for (size_t i =0; i<n;i++){
        cin >> army[i];
    }

    ll curr {};

    queue<ll> vals;
    set<ll> conquered; // size k

    // (m+n)(log n+ k logn)
    // worst case becomes m log n +n^2 log n  but that is too slow
    // max condition is that all remaining values are greater than curr
    // Can use fenwick tree to update values as we meet them all values of seen get changed to curr
    // if we see the minimum > curr we stop and return






}
