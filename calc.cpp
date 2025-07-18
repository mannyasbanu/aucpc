#include <iostream>
#include <stack>
using namespace std;
int main(){
  // record
  stack<int> s;
  // read inputs
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    // extract char
    char c;
    cin >> c;
    // +
    if(c == '+'){
      if(s.size() < 2){
        cout << "INVALID" << endl;
        return 0;
      }
      int num1 = s.top();
      s.pop();
      int num2 = s.top();
      s.pop();
      s.push(num1+num2);
    }
    // B
    else if(c == 'B'){
      if(s.empty()){
        cout << "INVALID" << endl;
        return 0;
      }
      s.pop();
    }
    // C
    else if(c == 'C'){
      while(!s.empty()){
        s.pop();
      }
    }
    // T
    else if(c == 'T'){
      if(s.empty()){
        cout << "INVALID" << endl;
        return 0;
      }
      int num = s.top();
      s.pop();
      s.push(num/3);
    }
    // D
    else if(c == 'D'){
      if(s.empty()){
        cout << "INVALID" << endl;
        return 0;
      }
      int num = s.top();
      s.pop();
      s.push(2*num);
    }else{
      // keypad
      int num = c - '0';
      if(num >= 0 && num <= 9){
        s.push(num);
      }else{
        cout << "INVALID" << endl;
        return 0;
      }
    }
  }
  if(s.size() != 1){
    cout << "INVALID" << endl;
  } else{
    cout << s.top() << endl;
  }
  return 0;
}