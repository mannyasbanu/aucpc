#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
int main(){
  int n; cin >> n;
  vector<string> names;
  unordered_map<string,string> namesOut;
  while(n--){
    string fname; cin >> fname;
    string lname; cin >> lname;
    names.push_back(lname + " " + fname);
    namesOut[lname + " " + fname] = fname + " " + lname;
  }
  sort(names.begin(), names.end());
  for(int i = names.size()-1; i >= 0; --i){
    cout << namesOut[names[i]] << endl;
  }
  return 0;
}