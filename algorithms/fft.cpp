#include <vector>
#include <complex>
#include <numbers> // For std::numbers::pi_v (C++20 onwards)


using namespace std;

using ll = long long;

using comp = complex<double>;

const double pi = numbers::pi_v<double>;

// converts coefficient representation to point representation which is much faster for multiplication from O(n^2) to O(n)
vector<comp> fft(vector<comp> polynomial){
    ll n = polynomial.size();
    if (n==1){
        return polynomial;
    }
    const comp i(0.0, 1.0);

    vector<comp> omega;
    vector<comp> p_e, p_o;

    for (int i =0; i <n; i++){
        // Calculate the exponent: 2 * pi * i
        comp exponent = (2.0 * pi * i)/static_cast<comp>(n);

        // Calculate e^(2 * pi * i)
        comp result = exp(exponent);
        omega.push_back(result);

        if (i %2 ){
            // odd
            p_o.push_back(polynomial[i]);
        }else{
            // even
            p_e.push_back(polynomial[i]);
        }
     }

    vector<comp> y_e = fft(p_e);
    vector<comp> y_o = fft(p_o);

    vector<comp> y (n, 0);
    for (int j =0; j<(n/2); j++){
        y[j] = y_e[j] + omega[j]*y_o[j];
        y[j+ static_cast<int>(n/2)] = y_e[j] - omega[j]*y_o[j];
    }

    return y;
}
