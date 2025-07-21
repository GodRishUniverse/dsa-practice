#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <exception>

using ll = long long;
using namespace std;

// LEARNING ALWAYS USE 0-based indexing

vector<pair<ll, ll>> answer;

vector<bool> sieve_of_eratosthenes(ll n){
    if (n<2){
        throw exception();
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

    return A;
}

void eswap(ll i, ll j, vector<ll>& where, vector<ll>& v){ 
    // cout << i << " " << j << endl;
    swap(v[i], v[j]);
    swap(where[v[i]], where[v[j]]);
    // for (size_t c =0 ; c < where.size(); c++ ) cerr << "WHERE : " << c << " -> " << where[c] <<endl;
    // for (size_t c =0 ; c < v.size(); c++ ) cerr << "Vals : " << c << " -> " << v[c] <<endl;
    answer.push_back({i+1, j+1});

}

vector<pair<ll,ll>> f(ll idx, vector<bool>& sieve, vector<vector<pair<ll,ll>>>& dp){
    if (idx < 0 || idx >= dp.size()) return {}; // Bounds check

    // cerr << "INDEX: " << idx << endl;
    if (!dp[idx].empty()) { 
        return dp[idx];
    }

    if (idx ==0 ){
        dp[idx] = {};
        return dp[idx];
    }
    if (sieve[idx+1]){
        dp[idx] = {{0, idx}};
        return dp[idx];
    }

    if (idx % 2 ==0 ){
        for (size_t i=1; i<=idx/2; i++ ){

            if (sieve[i+1] && sieve[idx-i+1]){
                dp[idx] = {{i, idx}, {0, i}};
                return dp[idx];
            }
        }
    }

    
    vector<pair<ll,ll>> s = f(idx-1, sieve, dp);
    dp[idx].reserve(s.size() + 1);  // Reserve space
    dp[idx].push_back({idx-1, idx});
    dp[idx].insert(dp[idx].end(), s.begin(), s.end());
    return dp[idx];
}


int main(){
    ll n;
    cin >> n;

    vector<bool> primes = sieve_of_eratosthenes(1e5+10);

    vector<ll> vals_to_indices (n, -1);
    vector<ll> vals(n, 0);
    vector<vector<pair<ll,ll>>> dp (n);

    for(size_t i =0; i<n; i++){
        cin>> vals[i];
        vals[i]--;
        vals_to_indices[vals[i]] = i;
    }

    ll count {0};
    for (size_t min =0 ; min <n; min++){
        ll i = vals_to_indices[min];
        
        f(i-min, primes, dp);
        // cerr << "RET COUNT: "<<vp.size() << endl;
        // for (size_t c =0 ; c < vp.size(); c++ ) cerr << "VP : " << vp[c].first << " -> " << vp[c].second <<endl;
        count+=dp[i-min].size();
        for (auto[l,r] :  dp[i-min]){
            eswap(min+l, min+r, vals_to_indices, vals);
        }
    }

    cout << count << endl;

    for (auto [p,q] : answer){
        cout << p << " " << q<< endl;
    }

}
