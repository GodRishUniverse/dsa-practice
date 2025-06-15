#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>

#define ll long long

using namespace std;

int main(){
    ll k, n,w;
    cin >> k >> n >>w;

    ll t  = w*(w+1)/2 *k;
    if (n>=t){
        cout << 0 << endl;
    }else{
        cout << t-n << endl;
    }
}
