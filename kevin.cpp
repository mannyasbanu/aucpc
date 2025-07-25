#include <iostream>
using namespace std;
#include <algorithm>
#include <unordered_map>
#include <vector>
int main(){
  int n; cin >> n; cin.ignore();
  unordered_map<string,int> m;
  vector<string> v;
  while(n--){
    string line; getline(cin, line);
    if(!m.count(line))v.push_back(line);
    m[line]++;
  }
  sort(v.begin(),v.end());
  for(int i = 0; i < v.size(); i++){
    cout << v[i] << " " << m[v[i]] << endl;
  }
  return 0;
}