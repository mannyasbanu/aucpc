#include <iostream>
using namespace std;
#include <unordered_map>
#include<vector>
int main(){
  int n, t; cin >> n >> t;
  unordered_map<int,int> map;
  vector<int> vals;
  while(n--){
    int x; cin >> x;
    vals.push_back(x);
    map[x]++;
  }
  int count = 0;
  for(int i = 0; i < vals.size(); i++){
    int x = vals[i];
    if(t!=0 && map.count(x-t))count+=map[x-t];
    else if(!t){
      count+=map[x-t]-1;
    }
  }
  if(!t)count/=2;
  cout << count << endl;
  return 0;
}