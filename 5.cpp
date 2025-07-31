#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n; cin >> n;
  ll min1 = INT32_MAX; ll min2 = INT32_MAX; string name1; string name2;
  while(n--){
    ll price; string name; cin >> price >> name;
    if(price < min1){
      min2 = min1; name2 = name1;
      min1 = price; name1 = name;
    }else if(price < min2){
      min2 = price; name2 = name;
    }
  }
  cout << name2 << endl;
  return 0;
}