#include <iostream>

using ll = long long;

using namespace std;

bool checkPrime(ll n){
    for (ll p = 2; p*p <=n ; p++){
        if (n%p == 0){
            return false;
        }
    }
    return true;
}
