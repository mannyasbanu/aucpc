#include <iostream>
using namespace std;
#include <unordered_map>
int main(){
  long n; cin >> n;
  unordered_map<long,long> win;
  for(long i = 1; i <= n; i++){
    long a; cin >> a;
    if(!win.count(a))win[a]=i;
  }
  cin >> n;
  long profit = -n*5;
  while(n--){
    long a; cin >> a;
    if(win.count(a)) profit += win[a];
  }
  cout << profit << endl;
  return 0;
}