#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long n; cin >> n;
  set<long> s;
  while(n--){
    long a; cin >> a;
    s.insert(a);
  }
  cin >> n;
  while(n--){
    long a; cin >> a;
    if(s.count(a)) continue;
    auto itr = s.upper_bound(a);
    if(itr == s.end()) s.insert(a);
    else{
      cout << "A greedy member at " << a << " has pushed in front of the member at " << *itr << ", this is terrible" << endl;
      s.insert(itr,a);
    }
  }
  return 0;
}