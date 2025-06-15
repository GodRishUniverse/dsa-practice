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
    cin >> n;
    bool flag {false};
    
    for (size_t i =0 ; i < n ; i++){
        ll a;
        cin >>a ;
        if (a==1){
            cout << "HARD" <<endl;
            flag = true;
            break;
        }
    }

    if (!flag){
        cout << "EASY" <<endl;
    }



   


}
