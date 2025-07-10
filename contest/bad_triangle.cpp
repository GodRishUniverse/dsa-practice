#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <set>


using namespace std;

using ll = long long;

int main(){
   ll tests {};
   cin >> tests;

   for (size_t t =0 ; t<tests; t++){
        ll n;
        cin >> n;
        vector<ll> a(n+1,0);
        for (size_t i =1; i < n+1; i++){
            cin >> a[i];
        }

        if ((a[1]+a[2]) <= a[n]){
            cout << 1 << " " << 2 << " " << n << endl;
        }else {
            cout << -1 << endl;
        }
   }


}
