#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>

#define ll long long

using namespace std;

int main(){
    ll a, b;
    cin >> a >> b ;

    ll c {0};

    while (a<=b){
        a*=3;
        b*=2;
        c++;
    }

    cout << c<< endl;


   
}
