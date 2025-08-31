#include <iostream>
#include <type_traits>

using ll = long long;
using namespace std;


template<typename T>
T identity(){
    if (is_same_v<T, ll>){
        return 1;
    }else {
        // TBD
    }
}

template<typename T>
T power_fast(T val, ll exponent){
    T ans = identity<T>();
    while (exponent >0){
        if (exponent % 2) {ans*=val;}
        val*=val;
        exponent/=2;
    }
    return ans;
}
