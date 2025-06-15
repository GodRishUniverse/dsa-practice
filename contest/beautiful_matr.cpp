#include <iostream>
#include <vector>
#include <string>

#define ll long long

using namespace std;

int main(){
    vector<ll> temp (5,0);
    vector<vector<ll>> matr(5, temp);

    ll ci {} ,cj {};
    
    for (size_t i =0; i < 5 ; i++){
        for (size_t j =0; j <5; j ++){
            cin >> matr[i][j];
            if (matr[i][j] ==1){
                ci = i;
                cj = j;
                break;
            }
        }
        // cerr << endl;
    }

    // middle index is 2,2

    cerr << "I = " << ci << " J = " << cj << endl;

    cout << abs(ci-2)+abs(cj-2) << endl;
    
   
}
