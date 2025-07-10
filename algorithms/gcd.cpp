#include <iostream>

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
