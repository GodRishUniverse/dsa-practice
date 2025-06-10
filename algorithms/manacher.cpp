#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iostream>

#define ll long long

using namespace std;

// USED to get the palindromes in the string (longest palindrome centred at each place)
// 

vector<ll> manacher(string s){
    ll n = s.length();
    vector<ll> z(n,0);

    ll l {}, r{};

    for (ll i =0 ; i <n; i++){
        if (i <r){
            z[i] = min(z[l+r-i], (r-i));
        }
        while ( ((i-z[i]) >=0 && (i+z[i])<n) && s[i-z[i]]==s[i+z[i]]){
            z[i]++;
        }
        if ((i+z[i])>r){
            l = i-z[i];
            r = i+z[i];
        }
    }
    return z;
}


int main(){
    string s = "aaa";
    string s_2 = "cabacabadabadabacababa";

    vector<ll> z = manacher(s);
    for (size_t i =0; i <z.size(); i++){
        cout << z[i] << " ";
    }
    cout << endl;

    cout << "---------------" <<endl;

    z = manacher(s_2);
    for (size_t i =0; i <z.size(); i++){
        cout << z[i] << " ";
    }
    cout << endl;

}
