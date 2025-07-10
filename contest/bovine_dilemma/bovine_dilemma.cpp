#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <set>


using namespace std;

using ll = long long;

int main(){
   ll tests {};
   cin >> tests;

   for (size_t t =0 ; t<tests; t++){
        ll trees {};
        cin >> trees;
        vector<ll> tree(trees, 0);
        for (size_t i = 0; i <trees; i++){
            cin >> tree[i];
        }
        
        set<ll> distincts;
        for (size_t i =0; i < trees-1; i ++){
            for (size_t j = i+1; j<trees;j++){
                if (i !=j){
                    ll a = tree[j] - tree[i];
                    ll b = -tree[i];

                    distincts.insert(a);
                }
            }
        }

        cout << distincts.size() << endl;
   }


}
