#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define ll long long

int main(){
    int n, p, q, m;
    int tests;
    cin >> tests;

    vector<string> answers;

    for (size_t t = 0; t <tests; ++t){
        cin >> n >> m >> p>> q;
        // n = length
        // m = sum
        // p = segment length 
        // q = length
        // there are n-p+1 segments

        // there definitely exists a sum of integers in array where sum is m - so we dont check for that 
        // we need to see if the segment conditions hold 
        // basically every segment 

        // [--- --- --- --]

        int mod = n % p;
        int quo = n/p; // no. of disjoint segments

        // disjoint sets sum = quo *q  (which should equal to m if mod =0)

        if (quo*q == m && mod ==0){
            answers.push_back("YES");
        } else if (mod!=0){
            answers.push_back("YES"); // since can be negative
        }else{
            answers.push_back("NO");
        }
    }

    for(auto s: answers){
        cout << s << endl;
    }

    // DRY run for 5 4 2 3
    // n = 5, m = 4, p =2 , q =3
    // n/p = 2, 2*3 = 6 , 
}
