#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define ll long long

using namespace std;

int main(){
    ll n, k;
    cin >> n >> k;
    
    vector<ll> l(n,0);
    for (int i =0 ; i < n; i++){
        cin >> l[i];
    }

    for (size_t i =0 ; i<l.size(); i++){
        cerr << l[i] << " ";
    }
    cerr << endl;
    cerr << "---------" << endl;

    ll c {};
    for (size_t i =n-1; i>0; i--){
        if (l[i]>0 && l[i]>=l[k]){
            c++;
        }
    }

    if (l[0]>0){
        c++;
    }

    cout << c << endl;
   
}
