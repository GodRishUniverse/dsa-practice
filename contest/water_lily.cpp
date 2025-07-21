#include <iostream>
#include <cmath>
#include <iomanip>

using ll = long long;
using namespace std;

int main(){
    ll h, l;
    cin >> h >> l;

    cout  << setprecision(10) <<static_cast<double>( (l*l - h*h)) / (2*static_cast<double> (h))<<endl;
}
