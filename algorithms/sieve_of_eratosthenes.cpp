#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <deque>
#include <queue>

using ll = long long;
using namespace std;

vector<ll> sieve_of_Eratosthenes(ll n){
    if (n<2){
        throw exception("NOT VALID");
    }

    vector<bool> A(n+1, true);

    A[0] = false;
    A[1] = false;

    for (ll i = 2; i*i<=n; i++){
        if (A[i]){
            for (ll j = i*i; j <=n; j+=i){
                A[j] =false;
            }
        }
    }

    vector<ll> values;
    for (ll i =2; i <n+1; i ++){
        if (A[i]){
            values.push_back(i);
        }
    }

    return values;
}

int main(){
    ll n {};
    cin >> n ;

    vector<ll> vals = sieve_of_Eratosthenes(n);

    for (size_t i =0 ; i<vals.size(); i++){
        cout << vals[i]<< " ";
    }
    cout<<endl;
}
