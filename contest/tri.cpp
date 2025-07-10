#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <set>


using namespace std;

using ll = long long;

int main(){
   ll a , b, c;
   cin >> a >> b >> c;

   if (a>b && a>c){
      if (a-b-c+1>0){
        cout << a-b-c+1 << endl;
      }else{
        cout << 0 << endl;
      }
   } else if (b>a && b>c){
      if (b-a-c+1>0){
        cout << b-a-c+1 << endl;
      }else{
        cout << 0 << endl;
      }
   }else if (c>a && c>a){
      if (c-b-a+1>0){
        cout << c-b-a+1 << endl;
      }else{
        cout << 0 << endl;
      }
   }


}
