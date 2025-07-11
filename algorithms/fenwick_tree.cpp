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

    FenwickTree(const vector<ll>& arr){
        this->n = arr.size();
        binary_indexed_tree.assign(arr.size()+1, 0);

        // the idea is the odd positions get the same number and the even numbers get the sum of the previous numbers
        for (size_t i =1; i <arr.size()+1; i++){
            add(i, arr[i-1]);
        }

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


    int query(int l, int r) {
        if (l<=0 || r<=0 || l>=this->n+1 || r>=this->n+1){
            throw invalid_argument("query: index has to be one based");
        }

        if (l == 1) return sum(r);
        else return sum(r) - sum(l-1);
    }
};


int main(){

    vector<ll> testArr {1,2,3,4,5,6,7,8,9,10};
    FenwickTree ft = FenwickTree(testArr);

    cout << "Sum from index 1 to index 9 is: (one-based indexing)" << ft.query(1, 9) <<endl; 



    
}
