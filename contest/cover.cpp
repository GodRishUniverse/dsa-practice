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

   ll m {INT_MIN};
   for (size_t t =0 ; t<tests; t++){
        ll x, y;
        cin >> x >>y;
        m = max(m, x+y);
   }

   cout << m << endl;


}
