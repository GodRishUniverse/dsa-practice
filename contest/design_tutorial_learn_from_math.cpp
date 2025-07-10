#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <deque>
#include <queue>

#define ll long long
using namespace std;

vector<ll> sieve_of_Eratosthenes(ll n){
    if (n<2){
        return {-1};
    }

    vector<bool> A(n+1, true);

    A[0] = false;
    A[1] = false;

    for (ll i = 2; i*i<n; i++){
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
    cin >> n;

    vector<ll> sieve = sieve_of_Eratosthenes(n);

    for (ll i = 4; i <n; i++){
        auto f_1 = find(sieve.begin(), sieve.end(), i);
        auto f_2 = find(sieve.begin(), sieve.end(), n-i);

        if (f_1 == sieve.end() && f_2 == sieve.end()){
            cout << i << " " << n-i<< endl;
            break;
        }
        
    }
}
