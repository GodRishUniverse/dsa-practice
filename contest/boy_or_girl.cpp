#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>

#define ll long long

using namespace std;

int main(){
    string name{};
    cin >> name;


    set<char> s;
    for (char c : name){
        s.insert(c);
      
    }

    if (s.size() %2 !=0){
        cout << "IGNORE HIM!" << endl;
    }else{
        cout << "CHAT WITH HER!" <<endl;
    }

    


   
}
