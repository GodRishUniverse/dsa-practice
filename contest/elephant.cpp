#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>

#define ll long long

using namespace std;

int main(){
    ll n; cin >>n;
    
    cout << n/5 + (n%5!=0)<<endl;
}
