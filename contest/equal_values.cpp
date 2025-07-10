#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <cstdint>

#define ll long long


using namespace std;
int main(){

    // value of a_i should be be the minimum

    // total cost is a_i *(n -1)
    // question is about longest subsequence of same number
        // the max subsequence would yield lowest n-i_j + i_k-1 value 
        // if that subsequence happens to have the minimum number as well then good
        // find all subsequence/substring - then calculate the score using (n-i_j+i_k-1) 
    // if no subsequence exist then minimum*(n-1) 

    ll tests;
    cin >> tests;

    for (size_t i =0 ; i <tests; i++){
        ll n;
        cin >> n;
        vector<ll> nums(n,0);
        for (ll j = 0; j<n ; j++){
            cin >> nums[j];
        }

        set<ll> keys;
        map<ll, ll> keys_to_max_size;

        for (int j = 0; j <n; j++){
            keys.insert(nums[j]);
            if (j==n){
                for (int k = j+1; k<n; k++){
                if (nums[k]!=nums[j]){
                    keys_to_max_size[nums[j]] = max(static_cast<ll>(k-j), keys_to_max_size[nums[j]]);
                    break; 
                }
            }
            }
        }

        ll minimum {INT64_MAX};
        for (ll k : keys){
            cout << k << " size = " << keys_to_max_size[k] << endl;
            minimum = min(minimum, k*(n-keys_to_max_size[k]));
        }

        cout << minimum << endl;
    }
}
