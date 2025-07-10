#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cmath>
#include <algorithm>

//TODO: fix this - doesnt work for all cases

using namespace std;
using ll = long long;

int main(){
    ll tests;
    cin >> tests;

    for (size_t i =0; i <tests; i++){
        ll l1, l2, l3, b1, b2, b3;
        cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;

        if (l1 < b1){
            // we check for l's

            swap(l1, b1);
            swap(b2, l2);
            swap(b3, l3);
        }

        if (l1 == l2  && l1 ==l3){
            if (b1+b2+b3 ==l1){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }else{

            if (l2+l3 ==l1 && (b2+b1 == l1 && b3+b1 == l1)){
                cout << "YES" <<endl;
            }
            else{
                cout << "NO" <<endl;
            }
           
        } 

    }
}
