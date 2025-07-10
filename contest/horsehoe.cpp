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
    ll s, ss,sss,ssss;
    cin >> s >>ss >> sss >> ssss;

    set<ll> vals;
    vals.insert(s);
    vals.insert(ss);
    vals.insert(sss);
    vals.insert(ssss);

    cout << 4 - vals.size() << endl;
}
