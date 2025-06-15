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
    ll sum{};
    for (size_t i = 0; i < n; i++)
    {
        ll p;
        cin >> p;
        sum += p;
    }

    cout << setprecision(10) << static_cast<double>(sum) / static_cast<double>(n) << endl;
}
