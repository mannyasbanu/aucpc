#include <iostream>
using namespace std;
#include <unordered_set>
#include <algorithm>
int main(){
  int n; cin >> n; cin.ignore();
  unordered_set<string> s;
  int count = 0;
  while(n--){
    string line; getline(cin,line);
    sort(line.begin(), line.end());
    if(!s.count(line)){
      count++;
      s.insert(line);
    }
  }
  cout << count << endl;
  return 0;
}