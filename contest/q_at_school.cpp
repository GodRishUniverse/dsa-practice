#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>

#define ll long long

using namespace std;

int main(){
    ll n ,t;
    cin >> n >> t;

    string s;
    cin >> s;

    vector<char> ss;
    for (int i =0 ; i<s.length(); i++){
        ss.push_back(s[i]);
    }

    for (int i =0 ; i<t; i++){
        for (int j =0 ; j <ss.size()-1; j++){
            if (ss[j]=='B' && ss[j+1]=='G'){
                ss[j] ='G';
                ss[j+1] ='B';
            }
        }
    }

    string temp {};
    for (int j =0 ; j <ss.size(); j++){
            temp+=ss[j];
    }

    cout  << temp << endl;

}
