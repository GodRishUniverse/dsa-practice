#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

using ll = long long;

// sum of i =1 to n of a_i (mod 10^9 +7 ) is a_n-1 + a_2
// USE int[][] instead of vectors to get a green mark
ll MOD = 1e9+7;

void printDebug(vector<vector<ll>>& mat){
    for (ll m = 0; m <mat.size(); m++ ){
        for (ll n =0; n<mat[0].size(); n++){
            cerr << mat[m][n] << ", ";
        }
        cerr << endl;
    }
}


vector<vector<ll>> matmul(vector<vector<ll>>& a, vector<vector<ll>>& b){
    // [m,n] * [n,k]
    vector<vector<ll>> res (a.size(), vector<ll>(b[0].size(),0));
    for (ll m =0; m<a.size(); m++){

        // row * column
        for (ll n =0; n<a[0].size(); n++){
            for (ll k =0; k<b[0].size(); k++){
                // cerr << m << " " <<  n << " " << k << " : " << a[m][n] << " * " << b[n][k] << endl;
                res[m][k] += (a[m][n]*b[n][k]) % MOD;
                res[m][k] %= MOD;
            }

        }
    }
    // printDebug(res);
    return res;
}

vector<vector<ll>> faster_pow(vector<vector<ll>>& a , ll n ){
    if (n ==0 ){
        //
        return  {{1,0,0}, {0,1,0}, {0,0,1}};
    }
    if (n % 2 ==0 ){
        vector<vector<ll>> c = faster_pow(a, n/2);
        return matmul(c,c);
    }else{
        vector<vector<ll>> c = faster_pow(a, n/2);
        vector<vector<ll>> temp = matmul(c,c);
        return matmul(temp,a);
    }
}

ll getSum(ll n, ll a1, ll a2){
    if (n ==1){
        return a1;
    }
    vector<vector<ll>> temp = {{1,-1,0}, {1,0,0}, {1, -1, 1}};
    temp = faster_pow(temp, n-2);
    vector<vector<ll>> temp_2 = {{a2}, {a1}, {a1+a2}};
    return(( MOD+((matmul(temp,temp_2)[2][0]) % MOD)) % MOD);
}


int main(){
    // vector<vector<ll>> temper {{2}};
    // cout << faster_pow(temper, 7)[0][0] << endl;

    ll t;
    cin >> t;
    while (t--){
        ll n, a1, a2;
        cin >> n >> a1 >> a2;
        // cerr << n << a1 << a2 << endl;
        cout << getSum(n, a1,a2) << endl;
    }
}
