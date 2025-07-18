#include <iostream>
#include <vector>
using namespace std;
int main(){
  // read each player into vector
  vector<int> v;
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    int num;
    cin >> num;
    v.push_back(num);
  }

  int i = 0;
  while(v.size() > 1){
    int sum = 0;
    // loop until sum is 100
    while(sum < 100){
      // add player sum
      sum += v[i]; 
      // cycle players
      i = (i+1) % v.size();
    }
    // remove player who exceeded 100
    int rmv = (i-1+v.size()) % v.size();
    v.erase(v.begin()+rmv);
    // left shift if rmv before current
    if(rmv < i)i--;
  }
  // return remaining player
  cout << v[0] << endl;
  return 0;
}