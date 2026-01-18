#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int tests;
    cin >> tests;
    while(tests--){
        int n;
        cin >> n;
        vector<int> v(n);
        int x = n;
        int zer = 0;
        int one = 0;
        int i = 0;
        while (n--){
            cin >> v[i];
            if(v[i] == 0) zer++;
            else if (v[i] == 1) one++;
            i++;
        }
        if (zer ==0){
            cout << "NO" << endl;
        } else if (zer == 1){
            cout << "YES" << endl;
        } else if (one ==0 && zer>=2){
            cout << "NO" << endl;
        }else {
            cout << "YES" << endl;
        }
    }

}
