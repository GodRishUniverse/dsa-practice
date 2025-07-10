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
        ll a, b,c;
        cin >> a >> b >> c;

        cout << max(a, max(b,c)) +1 << endl;
   }


}
