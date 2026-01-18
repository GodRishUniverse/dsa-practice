#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(){
    int tests;
    cin >> tests;
    while(tests--){
        int n;
        unordered_map<int, int> v;
        int t;
        int start = 0;
        cin >> n;
        int len = n;
        while (n--){
            cin >>t;
            v[t] = start;
            start ^=1; // this toggles afaik
        }

        bool flag = true;
        for (int i =1; i<len; i++) {
            if (v[i]==v[i+1]){
                cout << "NO" << endl;
                flag = false;
                break;
            }
        }
        if(flag) cout << "YES" << endl;
    }

}
