#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iostream>

#define ll long long

using namespace std;

// USED to get the palindromes in the string (longest palindrome centred at each place)
// 

vector<ll> gen_zf(string s){
    ll n = s.length();
    vector<ll> z(n,0);

    ll l {}, r{};

    for (ll i =0 ; i <n; i++){
        if (i <r){
            z[i] = min(z[l+r-i], (r-i));
        }
        while (  (i+z[i])<n && s[z[i]]==s[i+z[i]]){
            z[i]++;
        }
        if ((i+z[i])>r){
            l = i;
            r = i+z[i];
        }
    }
    return z;
}
