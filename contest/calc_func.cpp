#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>

#define ll long long

using namespace std;

int main(){
    ll n;
    cin >> n;

    // n is even - (n/2)(n/2+1)

    if (n %2 ==0){
        cout << n/2 << endl;
    }else{
        cout << -1* (n+1)/2 << endl;
    }

}
