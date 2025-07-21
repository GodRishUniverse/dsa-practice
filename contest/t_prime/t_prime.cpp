#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>


using ll = long long;
using namespace std;




vector<bool> sieve_of_eratosthenes(ll n){
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

    return A;

}


string t_prime(vector<bool>& primes, ll v){
    ll s = static_cast<ll>(sqrt(v));
    for (size_t i = s; i <s+2; i++){
        if (i*i ==v){
            if (primes[s]){
                return "YES";
            }
        }
    }
    return "NO";
}


int main(){
    ll tests;
    cin >> tests;
    vector<bool> primes = sieve_of_eratosthenes(1e6);

    while(tests--){
        ll val;
        cin >> val;
        if (val <4){
            cout << "NO" <<endl;
        }
        else{
            cout << t_prime(primes, val) <<endl;
        }
    }    
}
