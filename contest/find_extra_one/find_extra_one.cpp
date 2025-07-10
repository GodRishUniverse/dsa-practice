#include <iostream>
#include <vector>
#include <cmath>
#include <string>


using namespace std;

using ll = long long;

int main(){
    ll n;
    cin >> n;

    ll pos {};
    ll neg {}
;    for (size_t i =0 ; i <n; i++){
        ll x {}, y {};
        cin >> x >> y;

        if (x>0){
            pos++;
        }else if (x<0){
            neg++;
        }
    }

    if (pos<=1 || neg <=1 ){
        cout << "Yes" << endl;
    }else {
        cout << "No" << endl;
    }
}
