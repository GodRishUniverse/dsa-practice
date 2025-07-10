#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>

#define ll long long


using namespace std;
int main(){

    vector<ll> fibs {1,1,2,3,5,8,13,21,34,55,89};
    ll tests{};

    cin >> tests;

    for (size_t i =0 ; i <tests; i++){
        ll n,m;
        cin >> n >> m;

        string vals {""};

        for (int j = 0; j <m ; j++){
            ll w,l,h;
            cin >> w >> l>> h;
            ll minimum = min(l,min(h,w)); // the minimum will tell us the max that is possible
            ll maimum = max(l,max(h,w));
            if (minimum>=fibs[n] && maimum>=(fibs[n]+fibs[n-1])){
                // minimum >= fibs[n]
                // max >= fibs[n] + fibs[n-1]
                vals+="1";
            }else{
                vals+="0";
            }
        }
        cout << vals << endl;


    }

}



// bool flag {false};
//                 for (int s = n; s>=1; s--){
//                     l-=fibs[s]; // problem here
//                     w-=fibs[s]; // problem here
//                     h-=fibs[s]; // problem here
//                     if (l<0 || w<0 || h<0){
//                         flag = true;
//                         break;
//                     }
//                 }
//                 if (!flag){
//                     vals+="1";
//                 }else{
//                     vals+="0";
//                 }
