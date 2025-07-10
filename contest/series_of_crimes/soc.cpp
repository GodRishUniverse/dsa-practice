#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

using ll = long long;

int main(){
    ll n , m;
    cin >> n >> m;

    vector<pair<ll,ll>> coords;
    for (size_t i =1; i<n+1; i++){
     for (size_t j =1; j <m+1; j++){
        char c;
        cin >> c;
        if (c == '*'){
            coords.emplace_back(i,j);
        }
     }
    }

    ll minx {1000};
    ll miny {1000};

    ll maxx{-1};
    ll maxy {-1};


    for (int i =0; i <coords.size(); i++){
        maxx = max(maxx, coords[i].first);
        maxy = max(maxy, coords[i].second);
        minx = min(minx, coords[i].first);
        miny = min(miny, coords[i].second);
    }

    vector<pair<ll,ll>> temps;
    temps.emplace_back(maxx, maxy);
    temps.emplace_back(maxx, miny);
    temps.emplace_back(minx, maxy);
    temps.emplace_back(minx, miny);

    // for (size_t i =0; i <temps.size(); i++){
    //     cerr <<  i<<" : "<< temps[i].first << " " << temps[i].second << endl;
    // }

    for (size_t i =0; i <temps.size(); i++){
        auto f = find(coords.begin(), coords.end(), temps[i]);
        if (f == coords.end()){
            cout << temps[i].first << " " << temps[i].second << endl;
            break;
        }
    }

 

    

    


}
