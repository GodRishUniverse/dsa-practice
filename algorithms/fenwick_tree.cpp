#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

// source : https://www.youtube.com/watch?v=uSFzHCZ4E-8

struct FenwickTree{
    vector<ll> binary_indexed_tree;
    ll n;

    // constructor
    FenwickTree(int n) {
        this->n = n;
        binary_indexed_tree.assign(n+1, 0); // using one based indexing
    }

    // TODO: Make
    void make(const vector<ll>& arr){

    }

    // add - updates the index position with
    void add(ll index, ll value){
        while(index<binary_indexed_tree.size()){
            binary_indexed_tree[index]+=value;
            index+= index & -index; // add last set bit
        }
    }

    // sum
    ll sum(ll i){
        if (i<=0){
            throw invalid_argument("sum: index has to be one based");
        }
        ll s {0};
        while (i>0){
            s += binary_indexed_tree[i];
            i-=i & -i; // flips the last unset bit - example for this is 7 =(0111)_2 and lets compute what we get as (0111)-((0111) and (1001)) = (0111)-(0001)= 0110 = 6
        }
        return s;
    }

    // get the sum
    ll getSum( ll i){
        if (i<=0){
            throw invalid_argument("getSum: index has to be one based");
        }
        return sum(i) - sum(i-1);
    }
};


int main(){
    
}
