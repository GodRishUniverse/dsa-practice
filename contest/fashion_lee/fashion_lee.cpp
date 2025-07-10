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
        string ans = (n % 4 ==0) ? "YES" : "NO";
        cout << ans << endl;
   }


}
