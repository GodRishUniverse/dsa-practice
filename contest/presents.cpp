#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>

#define ll long long

using namespace std;

int main(){
    ll n;
    cin >> n;
    vector<ll> temp(n+1,0);
    for (size_t i =1 ; i<n+1 ; i++){
        ll p;
        cin >> p;
        temp[p] = i;
    }

    for (size_t i =1 ; i<n+1 ; i++){
        if (i!=n){
            cout  << temp[i] <<  " ";
        }else{
            cout  << temp[i];
        }
    }



}
