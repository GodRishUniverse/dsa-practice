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
        ll n, m;
        cin >> m >> n;
        if (m %n ==0){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }

   }


}
