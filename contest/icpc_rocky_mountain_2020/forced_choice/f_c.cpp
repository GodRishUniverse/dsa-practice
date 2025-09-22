#include <iostream>

using ll = long long ;

using namespace std;

int main(){
    ll n, p ,s;
    cin >> n >> p >> s;

    while (s--){
        ll m;
        cin >> m;
        bool keep = false;
        while (m--){
            ll temp;
            cin>> temp;
            if (temp == p){
                keep = true;
            }
        }
        if (keep){
            cout << "KEEP"<<endl;
        }else{
            cout << "REMOVE" << endl;
        }

    }

}
