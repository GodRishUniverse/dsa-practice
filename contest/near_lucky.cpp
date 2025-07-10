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

    ll l {};
    while(n>0){
        if (n%10 == 4 || n%10 ==7){
            l++;
        }
        n/=10;
    }

    if ( l== 7 || l ==4){
        cout << "YES" <<endl;
    }else{
        cout << "NO" <<endl;
    }
}
