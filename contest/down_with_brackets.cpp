#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

// find (( in string - if length == 4 - not
// find () in string - if length == 2 - not

int main(){

    int tests {};
    cin >> tests;
    cout.flush();

    for (int i =0; i < tests ; i++){
        string brackets;
        cin >> brackets;      
        if (brackets.length() >4 ){
            cout << "YES" << endl;

            // ((()))
        }else{
            // base cases
            if (brackets == "()"){
                cout << "NO" << endl;
            }else if ( brackets == "(())"){
                cout << "NO" << endl;
            }else{
                cout << "YES" << endl;
            }
        }
    }
}
