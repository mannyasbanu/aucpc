#include <iostream>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;
int main (){
    ll n; cin >> n;
    stack<ll> branch;
    ll tunnel = 1;
    queue<ll> line;
    while(n--){
        ll train; cin >> train;
        line.push(train);
    }
    while(!line.empty()){
        if(!branch.empty() && branch.top() == tunnel){
            tunnel++;
            branch.pop();
            continue;
        }
        if(line.front() == tunnel){
            tunnel++;
            line.pop();
        }else{
            branch.push(line.front());
            line.pop();
        }
    }
    while(!branch.empty() && branch.top() == tunnel){
        tunnel++;
        branch.pop();
    }
    cout << tunnel - 1 << endl;
    return 0;
}