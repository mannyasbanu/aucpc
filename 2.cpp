#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int main(){
  int n; cin >> n;
  vector<pair<long long,long long>> coords1;
  while(n--){
    long long x; long long y; cin >> x >> y;
    coords1.push_back({x,y});
  }
  cin >> n;
  vector<pair<long long,long long>> coords2;
  while(n--){
    long long x; long long y; cin >> x >> y;
    coords2.push_back({x,y});
  }
  long long max = 0;
  pair<long long, long long> c1;
  pair<long long, long long> c2;
  for(int i = 0; i < coords1.size(); ++i){
    for(int j = 0; j < coords2.size(); ++j){
      long long dx = coords1[i].first - coords2[j].first;
      long long dy = coords1[i].second - coords2[j].second;
      long long d = dx*dx + dy*dy;
      if(d > max){
        max = d;
        c1 = coords1[i]; c2 = coords2[j];
      }
    }
  }
  cout << c1.first << " " << c1.second << endl;
  cout << c2.first << " " << c2.second << endl;
  return 0;
}