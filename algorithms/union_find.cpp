#include <algorithm>
#include <vector>
#include <string>

// constuction is O(n)
// count is O(1)
// and Union and find themselves are amortized O(1)
//
// Used for grouping problems and then connecting them using union (Minimal spanning tree is an example)
// This is called disjoint set forest
// It allows to manager disjoint sets (and find between them) and merge sets if needed

using namespace std;

using ll = long long;

// https://en.wikipedia.org/wiki/Disjoint-set_data_structure
//
// make_set - creates a new set per child/node where it's parent is itself initially
// find- thr root of the group that it is part of
// union - merge groups if they are not part of them
//
// Resoruce: https://www.youtube.com/watch?v=92UpvDXc8fs
// Even though this is considered as a tree
// We use arrays for the implementation where index is the node and the value is its parent
// we look though each node and move to its parent till we find a self looping node (root of the tree)
// This forms a forest
//
// If elements are strings then a hashmap/unordered_map can be used to give them unique values


vector<int> make_set(int n){
    vector<int> arr(n,0);
    for (int i = 0; i <n; i++){
        arr[i]= i; // we make self parents
    }
    return arr;
}


int find(vector<int>& disjoint_set, int number){
    int root = number;
    while (root != disjoint_set[root]){
        root = disjoint_set[root];
    }
    return root;
}


void union_(vector<int>& disjoint_set, int first, int second){
    // we find the parent of each
    int parent_first = find(disjoint_set, first);
    int parent_second = find(disjoint_set, second);
    if (parent_first == parent_second){
        return;
    }
    disjoint_set[parent_second] = parent_first;
}
