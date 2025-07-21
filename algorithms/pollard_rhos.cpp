#include <iostream>
#include <vector>
#include <cmath>
#include <exception>

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


ll g(ll x, ll b, ll n){
    if (b<1 || b>n-2){
        throw exception();
    }

    return (x*x + b) % n;
}

ll pollard_rho(ll n, ll b= 1){
    ll x {2};
    ll y = x;
    ll d{1};

    while (d==1){
        x = g(x, b,n);
        y = g(g(y,b,n),b,n);
        d = gcd(abs(x-y), n);
    }

    if (d ==n){
        return -1; // denoting failure
    }else{
        return d;
    }
}

int main(){
    cerr << pollard_rho(8051) <<endl;
}
