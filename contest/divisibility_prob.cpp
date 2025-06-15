#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>

#include <iomanip>
#include <limits>
#include <numbers>

#define ll long long

using namespace std;

int main()
{
    ll t;
    cin >> t;

    for(size_t i =0 ; i <t; i++){
        ll a ,b;
        cin >> a >> b;
        ll c{};
        if (b>a){
            cout << b-a << endl;
        }else{
            cout << ceil(a/b)*b-a<<endl;
        }
    }
}
