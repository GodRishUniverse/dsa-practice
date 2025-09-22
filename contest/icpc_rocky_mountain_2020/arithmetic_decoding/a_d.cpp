#include <cmath>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;
using ld = long double;

// PROBLEM HERE AS DOESN't PASS TEST CASE 4
//
// DARCY says solution has only integer solution so DOUBLES IS WRONG


// string f(ll& N, ll tree_depth, string prev, ld a, ld b, ld& p_a, ld& final){
//     if (tree_depth==0){
//         cerr << a << " and ->" << final << endl;
//         if (a == final){
//             return prev;
//         }
//         return ""; // we skip
//     }

//     // pruning branches
//     if (a>final){
//         return "";
//     }
//     if (b<final){
//         return "";
//     }

//     ld c = a+p_a*(b-a);

//     string aa = prev+"A";
//     string bb = prev+"B";

//     string s1 = f(N, tree_depth-1, aa, a, c,p_a, final);
//     string s2 = f(N, tree_depth-1, bb, c, b, p_a, final);
//     cerr << s1 << " and s2 is " << s2 << endl;

//     return (s1.length() == N) ? s1 : s2;
// }


// int main(){
//     // tree depth is N
//     ll N, D;
//     cin >> N;
//     cin >> D;

//     vector<ld> vals(3*N+2, 0.0);

//     for (ll i =3; i<3*N+1; i++){
//         vals[i-1] = pow(2.0, -i+2);

//         cerr << setprecision(20) << vals[i-1] << " and index is "<<i-1 << endl;
//     }

//     ld p_a = static_cast<ld>(D)/8.0;

//     string s;
//     cin >> s;

//     ld prob {0};

//     ll count {};
//     for (char c : s){
//         if (count>=2) prob += static_cast<ld>(c-'0')*vals[count];
//         count++;
//     }

//     cout << f(N, N, "", 0.0, 1.0, p_a, prob)<< endl;
// }



int main(){
    // tree depth is N
    ll N, D;
    cin >> N;
    cin >> D;

    ll divisor = 8;

    string s;
    cin >> s;

    s = s.substr(2, s.length()); // remove 0 and .

    // we pad the s to make it divisible by 3
    while (s.length() != 3*N){
        s+= "0";
    }
    string res;

    ll running = 0;
    string A ="A";
    string B = "B";

    ll a = 0;
    ll b = D;

    for(size_t i =0; i<s.length(); i+=3){
        if (s[i+0] == '1'){
            running+=4;
        }
        if (s[i+1] == '1'){
            running+=2;
        }

        if (s[i+2]=='1'){
            running+=1;
        }

        cout << running << " B= " <<b  << " and A = " << a << " and divisor is " << divisor<< endl;

        if(running<=b && running>=a){
            res+=A;
            a*=8; // as divisor increases by 8
            b= a+ D*(b-a/8);
        }else{
            res+=B;
            a*=8;
            ll c =  a+ D*(b-a/8);
            a = c;
            b*=8;
        }

        running*=8;

        divisor*=8;
    }

    cout << res<< endl;


}
