#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using ll = long long;

using namespace std;


int main(){
    ll t;
    cin >>t;
    while (t--){
        string plus_or_minus;
        ll m, o;
        cin >> m >> o >> plus_or_minus;
        double ans;
        if(plus_or_minus == "+"){
            ans = static_cast<double>(m*o/100);
        }else{
            ans = (static_cast<double>(m)/static_cast<double>(o))*100;
        }
        cout << fixed << setprecision(5);
        cout << ans << endl;
    }
}
