#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cmath>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
    ll tests;
    cin >> tests;

    for (size_t i =0; i <tests; i++){
        ll n, s;

        cin >> n >> s;
        vector<pair<ll,ll>> pockets {{0,0}, {0,s}, {s,0}, {s,s}};

        vector<vector<ll>> vals(n, {0,0,0,0});
        for (size_t j =0; j <n; j++){
            cin >> vals[j][0] >> vals[j][1] >> vals[j][2] >> vals[j][3];
        }

        


    }
}
