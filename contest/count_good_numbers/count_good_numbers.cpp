#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

// TODO: problem - difference of 1 with actual values - rounding errors

using namespace std;

using ll = long long;

ll f (ll r, ll l){
    // TODO: use loop for this inclusion-exclusion principle
    return r- ((r-l)/2 + 
        (r-l)/6 +
        (r-l)/15 +
        (r-l)/7 - (r-l)/(2*5*7) - (r-l)/(2*3*7) - ((r-l)/(2*7) - (r-l)/(2*5*7) - (r-l)/(2*3*7) +  (r-l)/(2*3*5*7)) - ((r-l)/(3*7) - (r-l)/(3*5*7) - (r-l)/(2*3*7) + (r-l)/(2*3*5*7)) - ((r-l)/(5*7) - (r-l)/(3*5*7) - (r-l)/(5*2*7) + (r-l)/(2*3*5*7)));
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); 

    ll t;
    cin >> t;
    while (t--){
        ll l, r;
        cin >> l >>r;

        cout << f(r+1,0) - f(l+1,0) << endl;
    }
}

