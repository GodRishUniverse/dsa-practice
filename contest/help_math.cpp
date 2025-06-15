#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define ll long long

using namespace std;

int main(){
    vector<ll> temp;

    string s;
    cin >>s ;

    for (size_t i =0 ; i<s.length(); i++){
        if (s[i]!='+'){
            temp.push_back(static_cast<ll>(s[i]-'0'));
        }
    }

    sort(temp.begin(), temp.end());

    for (size_t i =0 ; i<temp.size(); i++){
        if (i != temp.size()-1){
            cout << temp[i] <<"+";
        }else{
            cout << temp[i];
        }
    }
    
    
   
}
