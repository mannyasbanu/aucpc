#include <queue>
#include <iostream>
using namespace std;
int main(){
  int n;
  cin >> n;
  cin.ignore();
  queue<string> printq;
  // read each string
  for(int i = 0; i < n; i++){
    // add each string to queue
    string s;
    getline(cin, s);
    printq.push(s);
  }
  // loop while queue not empty
  while(!printq.empty()){
    // extract string
    string s = printq.front();
    printq.pop();
    // print up to 80 chars
    int i = 0;
    while(i < s.length() && i < 80){
      cout << s[i];
      i++;
    }
    cout << endl;
    // add remaining to end of queue
    if(i < s.length()){
      printq.push(s.substr(i, s.length()-i));
    }
  }
  return 0;
}