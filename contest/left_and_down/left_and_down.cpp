#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using ll = long long;

using namespace std;


ll gcd(ll a, ll b) {
    while (b != 0) {
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;  // now b==0, so a is gcd.
}


// max value can be 3 because (1,1), (1,0) and (0,1) can reduce anything to 0,0
ll f(ll a, ll b, ll k){
    if ((a<=k && b<=k) || (a/gcd(a,b)<=k && b/gcd(a,b)<=k )){
        return 1;
    }
    return 2;
}


int main(){
    ll t;
    cin >> t;
    while(t--){
        ll a,b,k;
        cin >> a >> b>>k;
        cout << f(a,b,k) << endl;
    }
}
