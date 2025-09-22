#include <iostream>

using namespace std;

using ll = long long;

int main(){
    ll n;
    cin >> n;

    if (n % 2){
        cout << "still running" << endl;
    }else{
        ll diff = 0;
        ll prev {};
        for (ll i =1; i<=n ;i ++){
            ll v;
            cin >> v;
            if (i%2){
                prev =v;
            }else{
                diff+= v-prev;
            }
        }
        cout << diff <<endl;
    }


}
