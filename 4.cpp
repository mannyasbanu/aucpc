#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll mass; cin >> mass;
  ll n; cin >> n;
  vector<ll> players;
  while(n--){
    ll p; cin >> p;
    players.push_back(p);
  }
  sort(players.begin(), players.end());
  for(ll i = 0; i < players.size(); ++i){
    if(players[i] < mass) mass += players[i];
  }
  if(mass > players[players.size()-1]) cout << "Yes!" << endl;
  else cout << "L Bozo." << endl;
  return 0;
}