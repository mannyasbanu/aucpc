#include <iostream>
using namespace std;
#include <unordered_set>
int main(){
  int n; cin >> n;
  cin.ignore();
  unordered_set<string> names;
  while(n--){
    string name; getline(cin,name);
    if(names.count(name)) cout << name << endl;
    else names.insert(name);
  }
  return 0;
}