#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>

#define ll long long

using namespace std;

int main(){
    ll n; cin >>n;
    string s;
    cin >> s;

    ll c {};
    ll temp{};
    for (int i =1; i < s.length();i++){
        if (s[temp] == s[i]){
            c++;
        }else{
            temp=i;
        }
    }
    cout << c << endl ;
}
