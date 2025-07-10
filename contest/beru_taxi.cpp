#include <iostream>
#include <algorithm>
#include <cmath>
#include <cfloat>
#include <iomanip>

using namespace std;
using ll = long long;

int main() {
    ll x_o, y_o;
    cin >> x_o >> y_o;
    
    int tests;
    cin >> tests;
    
    double min_time {DBL_MAX}; 
    
    for (int i = 0; i < tests; i++) {
        ll x, y, v;
        cin >> x >> y >> v;
        
        double time = sqrt(static_cast<double>((x_o - x)*(x_o - x) + (y_o - y)*(y_o - y))) / v;
        min_time = min(min_time, time);
    }
    
    cout << fixed << setprecision(10) << min_time << endl;
    
    return 0;
}
