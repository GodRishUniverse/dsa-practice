#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;
// need to find coprimes from 1 to 2n
// 1 is not allowed

// WHEN TALKING ABOUT DIVISORS -> THINK ABOUT multiples
void printer(ll n){
    for (ll i = n+1; i<=2*n; i++){
        cout << i << " ";
    }
    cout << endl;
}



int main(){
    ll t;
    cin >> t;
    while (t--){
        ll n;
        cin >> n;
        printer(n);
    }
}
