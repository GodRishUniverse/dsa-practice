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
    string s;
    string f;

    cin >> f;
    cin >> s;

    string c {};

    for (size_t i =0 ; i<s.length(); i++){
        c+= (s[i]==f[i]) ? "0" : "1";
    }

    cout << c << endl;
}
