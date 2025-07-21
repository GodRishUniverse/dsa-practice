#include <iostream>
#include <vector>
#include <limits.h>
#include <cmath>    

using ll = long long;

using namespace std;
ll func( ll n, ll k){
    ll minx {LONG_MAX};
    ll miny {LONG_MAX};
    ll maxy{LONG_MIN};
    ll maxx {LONG_MIN};

    vector<pair<ll,ll>> arr;

    for (size_t i =0; i<n; i++){
        ll x, y;
        cin >> x >>y;
        arr.emplace_back(x,y);
    }

    for (size_t i =0; i<arr.size(); i++){
        ll c {0};

        ll x = arr[i].first;
        ll y = arr[i].second;

        for (size_t j =0; j<arr.size(); j++){
            ll x_j = arr[j].first;
            ll y_j = arr[j].second;
            if (i != j && (abs(x - x_j) + abs(y-y_j))<=k){
                c++;
            }
        }

        if (c == n-1){
            return 1;
        }
          
    }

    return -1;

}

int main(){
    ll t;
    cin >> t;

    while(t--){
        ll n,k;
        cin >> n >>k;
        cout << func(n,k) << endl;
    }
}
