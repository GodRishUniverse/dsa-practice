#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>

#define ll long long

using namespace std;

int main(){
    ll n ;
    cin >> n;
    ll c {};

    ll val {};
    for (size_t i =0 ; i < n ; i++){
        ll a ,b; 
        
        cin >> a >> b;

        c-=a;
        c+=b;

        val = max(c, val);
    }

    cout << val << endl;

   


}
