#include <iostream>
#include <vector>

using namespace std;

using points = pair<int, int>;

double intersection(points a, points b, double x){
    double m= (static_cast<double>(b.second )-static_cast<double>(a.second)  )/ (static_cast<double>(b.first) - static_cast<double>(a.first));
    double c = static_cast<double>(a.second) -  m*static_cast<double>(a.first);

    return m*x+c;
}

vector<points> merge(vector<points> a, vector<points> b, double x){
     int i = 0;
     int j = 0;
     // upper tangent computation
     while ((j+1<b.size() && intersection(a[i], b[j+1], x) > intersection(a[i], b[j], x)) || (i+1<a.size() && intersection(a[i+1], b[j], x) > intersection(a[i], b[j], x))){
         if (intersection(a[i], b[j+1], x) > intersection(a[i], b[j], x)){
             j = (j+1) % b.size();
         }else{
             i = (i-1) % a.size();
         }
     }
     // lower tangent computation
     int i_lower = 0;
     int j_lower = 0;
     // upper tangent computation
     while ((j_lower+1<b.size() && intersection(a[i_lower], b[j_lower+1], x) < intersection(a[i_lower], b[j_lower], x)) || (i_lower+1<a.size() && intersection(a[i_lower+1], b[j_lower], x) < intersection(a[i_lower], b[j_lower], x))){
         if (intersection(a[i_lower], b[j_lower+1], x) < intersection(a[i_lower], b[j_lower], x)){
             j_lower = (j_lower-1) % b.size();
         }else{
             i_lower = (i_lower+1) % a.size();
         }
     }
     vector<points> combined;
     combined.push_back(a[i]);
     int k = j;
     while (k != j_lower){
         combined.push_back(b[k]);
         k = (k+1) %b.size();
     }
     combined.push_back(b[j_lower]);
     k = i_lower;
     while (k != i){
         combined.push_back(a[k]);
         k = (k-1) %a.size();
     }
     return combined;
}
vector<points> convex_hull(vector<points> s, double x){
    if (s.size() ==2){
        return s; // base case as we only have one segment here
    }
    int mid = s.size()/2;


    vector<points> a = vector<points>(s.begin(), s.begin()+mid);
    vector<points> b = vector<points>(s.begin()+mid+1, s.end());
    vector<points> ch_a = convex_hull(a, x/2);
    vector<points> ch_b = convex_hull(b, x+x/2);
    return merge(ch_a, ch_b, );
}



int main(){

}
