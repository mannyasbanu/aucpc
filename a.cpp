#include <iostream>
using namespace std;
typedef long long ll;
int main(){
    ll sum = 0;
    ll n; cin >> n;
    for(auto i = 0; i < n; ++i){
        ll num; cin >> num;
        sum+=num;
    }
    ll count = sum/50;
    if(count > n) count = n;
    cout << count << endl;
    return 0;
}