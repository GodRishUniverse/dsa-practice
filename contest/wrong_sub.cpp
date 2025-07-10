#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>

#define ll long long

using namespace std;

int main(){
    ll n,k;
    cin >> n   >> k;

    for (size_t i =0; i <k ; i++){
        if (n%10 ==0){
            n/=10;
        }else{
            n-=1;
        }
    }
    cout << n << endl;
}
