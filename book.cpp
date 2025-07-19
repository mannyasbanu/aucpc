#include <iostream>
using namespace std;
#include <stack>
int main(){
    stack <int> s;
    int n; cin>>n;
    while(n--){
        int num; cin>>num;
        while(!s.empty() && num > s.top()) s.pop();
        s.push(num);
    }
    cout << s.size() << endl;
    return 0;
}