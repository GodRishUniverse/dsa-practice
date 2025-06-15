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

    string prev {};

    ll c {1};
    for (size_t i =0 ; i<n; i++){
        string s;
        cin >>s;

        if (prev != ""){
            if (prev[1] == s[0]){
                c++;
            }
        }
        prev = s;
    }

    cout << c << endl;
}
