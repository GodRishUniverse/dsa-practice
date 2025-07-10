#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

#define ll long long

int main(){
    int tests;
    int n;

    cin >> tests;

    for (size_t t = 0; t <tests; ++t){
        cin >> n;
        int temp;
        int tmpN {n};
        vector<int> tempV;
        while (tmpN != 0){
            cin >> temp;
            tempV.push_back(temp);
            tmpN--;
        } 

       // make the first value negative and make all of them positive
       // then check if there are enough values larger absolutely to see if they can be changed signs 
       // if there are enough larger values then a[1] will become the median
       // used one - based indices

       // repeat above with first value as positive  - so 2 cases

       //TODO: implement
    }  

}
