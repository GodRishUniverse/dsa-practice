#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>

#include <iomanip>
#include <limits>
#include <numbers>

#define ll long long

using namespace std;

int main()
{
    ll n;
    cin >> n;
    
    string hate {"I hate"};
    string love {"I love"};
    string that{"that"};

    vector<string> s;

    for (size_t i =0 ; i<n; i++){
        if (i%2==0){
            s.push_back(hate);
        }else{
            s.push_back(love);
        }
    }

    string c {};
    for (size_t i =0 ; i<s.size(); i++){
        if (i != s.size()-1){
            c+= s[i] + " that ";
        }else{
            c+=s[i];
        }
    }

    cout << c << " it" <<endl;
}
