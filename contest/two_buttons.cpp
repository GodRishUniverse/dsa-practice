#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

#define ll long long

using namespace std;


const ll INF = 10e5;

// there is a more optimal solution with BFS - think about it

// prune the tree - where the node exceeds 20000 and dont add it in queue if already visited the number
int main(){
    ll n, m; 
    cin >> n >> m;
    // start with n and reach m
    // red button operation - double
    // blue button operation - reduce by one


    if (m==n){
        cout <<0 << endl;
    }else if (m<n){
        cout << n-m << endl;
    }else{

        // tree structure - search tree - apply bfs for operations since if we get m, we stop, if we get negative we stop also
        auto red = [](ll x) -> ll {return 2*x;};
        auto blue = [](ll x) -> ll {return x-1;};

        using clicks = pair<ll, ll>;
        queue<clicks> q ;
        q.push({n,0});

        int curr_click {0};
        
        while (!q.empty()){
            auto [popped, click] = q.front(); q.pop();
            // cout<< "Popped : " << popped << " Click time: " << click << endl;

            if (popped ==m){
                cout << click << endl; // since BFS - we only need to break once we get the m
                break;
            }else if (popped <0){
                // skip the cases for number being negative
            }
            else{
                q.push({red(popped), click+1});
                q.push({blue(popped), click+1});
                
            }
        }
    }

}


// int main(){

//     ll n, m; 
//     cin >> n >> m;

//     if (m==n){
//         cout <<0 << endl;
//     }else if (m<n){
//         cout << n-m << endl;
//     }else{
//         // backward pass
//         int clicks {0};
//         while (m> n){
//             if (m %2 ==0){
//                 // even
//                 m = m >>1;   
//             }else{
//                 m+=1;
//             }
//             ++clicks;
//         }
//         clicks+= n-m; // blue remaining clicks cause now m<n 
//         cout << clicks << endl;
//     }

    
// }
