#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>

#define ll long long

using namespace std;

int main(){
    ll n ;
    cin >> n ;

    ll c{};
    for (int i =0 ; i <n; i++){
        ll p, q;
        cin >> p >> q;
        if (q-p>=2){
            c++;
        }
    }

    cout << c << endl;

    

}
