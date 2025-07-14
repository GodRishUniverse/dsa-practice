#include <iostream>
#include <vector>
#include <limits.h>
#include <cmath>    
#include <iomanip>

using ll = long long;

using namespace std;
double func( ll n, ll k){
    vector<pair<ll, ll>> arr;
    for (size_t i =0; i <n; i++){
        ll x, y;

        cin >> x >>y;
        arr.emplace_back(x,y);


    }

    double dist {0};

    for (size_t i =0; i <n-1; i++){
        dist+= hypot((arr[i+1].first - arr[i].first), (arr[i+1].second - arr[i].second));
    }

    return dist*k/50.f;

}

int main(){
    ll n,k;
    cin >> n >>k;
    cout << setprecision(10) <<func(n,k) << endl;
}
