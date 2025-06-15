#include <iostream>
#include <vector>
#include <string>

#define ll long long

using namespace std;

int main(){
    ll w;
    cin >> w;
    
    ll count {};
    for (int i =0 ; i < w; i++){
        ll f,s,t;
        cin >> f >> s >> t;

        count+= (f+s+t>=2) ? 1 :0;
    }

    cout << count << endl;
}

