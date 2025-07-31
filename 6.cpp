#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  unordered_map<ll,ll> m;
  ll n; cin >> n;
  for(int i = 1; i <= n; ++i){
    ll s; cin >> s;
    m[s]=i;
  }
  cin >> n;
  ll score=0;
  while(n--){
    int s; cin >> s;
    if(m.count(s)) score += m[s];
  }
  cout << score << endl;
  return 0;
}