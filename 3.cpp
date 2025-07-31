#include <iostream>
#include <vector>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n1; int n2;
  cin >> n1 >> n2;
  vector<int> logs1(n1);
  vector<int> logs2(n2);
  for(int i = 0; i < n1; ++i) cin >> logs1[i];
  for(int i = 0; i < n2; ++i) cin >> logs2[i];
  int i = 0; int j = 0;
  while(i < n1 && j < n2){
    if(logs1[i] <= logs2[j]) cout << logs1[i++] << " ";
    else cout << logs2[j++] << " ";
  }
  while(i < n1) cout << logs1[i++] << " ";
  while(j < n2) cout << logs2[j++] << " ";
  cout << endl;
  return 0;
}