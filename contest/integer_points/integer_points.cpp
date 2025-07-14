#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;


ll func(){
    ll n;
    cin >> n;

    ll o_n {0};


    for (size_t i =0; i<n; i++){
        ll p;
        cin >> p;
        if (p % 2 ){
            o_n++;
        }
    }

    ll m;
    cin >> m;
    
    ll o_m {0};

    for (size_t i =0; i<m; i++){
        ll q;
        cin >> q;
        if (q % 2 ){
            o_m++;
        }
    }
    

    // cerr << "FOUND: n =" << n << " : " << o_n << ", " << m << " : " << o_m <<endl;
    return (o_n)*(o_m) + (n-o_n)*(m-o_m);
}

int main(){
    ll t;
    cin >> t;
    while (t--){
        cout << func() <<endl;
    }
}
