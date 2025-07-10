#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

#define ll long long

using namespace std;

int main(){
    ll n, m;
    cin >> n >> m;

    ll size = n*m/4;

    cerr << "SIZE = " << size << endl;

    size*=2;
    cerr << "2 * SIZE = " << size << endl;
    size+= (n*m-size*2 >=2) ?1:0;
    cerr << "Final SIZE = " << size << endl;

    cout << size << endl;


    
    
   
}
