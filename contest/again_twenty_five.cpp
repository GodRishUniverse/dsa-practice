#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

#define ll long long 

using namespace std;

/*

120, 50

(((2^20 %100 * 2^50 %100) %100) * 2^50 %100) %100

*/
// inline ll func(ll rem, ll sub){
//     return (rem>sub) ? ((func(rem-sub, sub)) * (static_cast<ll>(pow(5, sub)) % 100)) %100 : static_cast<ll>(pow(5, rem)) % 100 ; 
// }

int main(){
    ll n {};
    cin >> n;

    cout << 25 << endl;
}
