#include <iostream>
#include <algorithm>
#include <cmath>
#include <cfloat>
#include <iomanip>

using namespace std;
using ll = long long;

int main() {
    ll tests;
    cin >> tests;

    for (size_t i =0; i <tests; i++){
        ll n;
        cin >> n;
        if (n % 2 != 0){
            cout << "NO" << endl;
        }else {
            while (n %2 ==0){
                n/=2;
            }
            if (n ==1 || sqrt(n)- floor(sqrt(n))==0){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }
}
