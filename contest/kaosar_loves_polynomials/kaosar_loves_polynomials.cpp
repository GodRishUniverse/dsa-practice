#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

ll MOD = 1e9+7;


ll power_fast(ll val, ll exponent){
    ll ans = 1;
    while (exponent >0){
        if (exponent % 2) {
            ans*=val;
            ans %=MOD;
        }
        val*=val;
        val%=MOD;
        exponent/=2;
    }
    return ans;
}

ll f(ll k, ll n){
    ll val {};
    // the idea is that x is 1 so the polynomial is basically sum of the coefficients to them power k
    for (ll i = 0; i<=n;i++){
        ll t;
        cin >> t;
        val+=t;
        val%=MOD;
    }

    return ((MOD + (power_fast(val, k) % MOD))% MOD);
}

int main(){
    ll t;
    cin >> t;
    while (t--){
         ll k, n;
         cin >> k >> n;
         cout << f(k, n) << endl;
     }
}
