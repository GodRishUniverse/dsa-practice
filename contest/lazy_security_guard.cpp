#include <iostream>
#include <cmath>

using ll = long long;
using namespace std;


ll func(ll n){
    if (static_cast<ll>(floor(sqrt(n))*floor(sqrt(n))) == n){
        return 4*static_cast<ll>(floor(sqrt(n)));
    }else {
        if (static_cast<ll>(floor(sqrt(n))*floor(sqrt(n))) < n && (static_cast<ll>(floor(sqrt(n))*(floor(sqrt(n))+1)) >= n)){
            return 4*static_cast<ll>(floor(sqrt(n)))+2;
        }else{
            return 4*static_cast<ll>(floor(sqrt(n)))+4;
        }
    }
}


int main(){
    ll n;
    cin >> n;
    cout << func(n)<<endl;
}
