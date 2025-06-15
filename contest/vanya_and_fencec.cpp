#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>

#define ll long long

using namespace std;

int main(){
    ll n ,h;
    cin >> n >> h;

    ll c {};
    for (size_t i =0 ; i < n ; i++){
        ll temp {};
        cin >> temp;
        c+= (temp>h) ? 2:1;
    }
    cout << c <<endl;
}
