#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
typedef long long ll;
struct Intersection{
    string name;
    ll risk;
    vector<Intersection*> links;
};
int main(){
    unordered_map<string,Intersection*> intersections;
    ll n; cin >> n;
    for(auto i = 0; i < n; ++i){
        string name; ll risk; cin >> name >> risk;
        Intersection *inter = new Intersection();
        inter->name = name; inter->risk = risk;
        intersections[name] = inter;
    }
    ll m; cin >> m;
    for(auto i = 0; i < m; ++i){
        string st, i1, i2; ll risk; cin >> st >> i1 >> i2 >> risk;
        intersections[i1]->links.push_back(intersections[i2]);
        intersections[i2]->links.push_back(intersections[i1]);
        
    }
}