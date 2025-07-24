#include <iostream>
#include <vector>
#include <exception>

using ll = long long;
using namespace std;


vector<ll> prime_factors(ll n) {
    vector<ll> prime_facs;

    if (n<2){
        throw exception();
    }
  
    // Print the number of 2s that divide n 
    while (n % 2 == 0) {
      
        prime_facs.push_back(2);
        n = n/2; 
    } 

    // n must be odd at this point. So we can skip 
    // one element (Note i = i +2) 
    for (int i = 3; i*i <= n; i = i + 2) {
        // While i divides n, print i and divide n 
        while (n % i == 0) {
            prime_facs.push_back(i); 
            n = n/i; 
        } 
    } 

    // This condition is to handle the case when n 
    // is a prime number greater than 2 
    if (n > 2) 
        prime_facs.push_back(n);
    
    return prime_facs;
} 

// TODO: This TLEs - NEED TO FIX
// we need to get the number of prime factors - we know the number will never be prime because factorial
ll f(ll a , ll b){

    ll number = 0;
    cerr << a << " and " << b << endl;
    // does not work 20! > 10^18
    for(ll i = b+1; i <= a; i++) {
        number += prime_factors(i).size();
    }
    cerr << "NUMBER = " << number << endl;
    return number;
}

int main(){

    ll t;
    cin >> t;
    while (t--){
        ll a ,b;
        cin >> a >> b;
        cout << f(a,b) << endl;
    }
}
