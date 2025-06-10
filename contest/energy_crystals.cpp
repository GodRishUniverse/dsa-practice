#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

#define ll long long


// ll getMinIndex(ll a, ll b, ll c){
//     if (c<=a && c<=b ){
//         return 2;
//     }else if (b<=a && b<=c ){
//         return 1;
//     }else{
//         return 0;
//     }
// }

using namespace std;
int main(){

    int tests{};

    cin >> tests;

    for (size_t i = 0; i < tests; i++){
        ll batt_size {};
        cin >> batt_size;
        vector<ll> A(3,0);
        ll steps {};

        while(A[0]<batt_size || A[1]<batt_size || A[2]<batt_size){
            if (A[0]<= A[1] && A[0]<=A[2] ){
                A[0] = min(2*A[1]+1, 2*A[2]+1);
            }else if (A[1]<= A[0] && A[1]<=A[2] ){
                A[1] = min(2*A[0]+1, 2*A[2]+1);
            }else{
                A[2] = min(2*A[0]+1, 2*A[1]+1);
            }
            steps++;
        }
        cout << steps << endl;
    }
}


