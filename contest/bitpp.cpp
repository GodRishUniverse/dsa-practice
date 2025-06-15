#include <iostream>
#include <vector>
#include <string>

#define ll long long

using namespace std;

int main(){
    ll w;
    cin >> w;
    
    ll c {};
    for (int i =0 ; i < w; i++){
       string s {};
       cin >> s;

       if (s[0] == '+' && s[1] =='+'){
            ++c;
       } else if (s[1] == '+' && s[2] =='+'){
            c++;
       } else if (s[0] == '-' && s[1] =='-'){
            --c;
       } else if (s[1] == '-' && s[2] =='-'){
            c--;
       }


    }

    cout << c << endl;

   
}
