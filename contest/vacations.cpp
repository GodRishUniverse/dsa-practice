#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;
int main(){
    ll n {};
    cin >> n;

    vector<ll> vals(n, 0);
    for (size_t i = 0; i <n ;i ++){
        cin >> vals[i];
    }

    // direct method won't work
    // n - maximum days working = minimum vacation
    //TODO: 

}
