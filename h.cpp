#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main (){
    ll n; cin >> n;
    ll k; cin >> k;
    ll i = 1;
    ll j = 1;
    while(i <= n){
        ll a; cin >> a;
        while(a >= k){
            if(j == n){
                cout << i << " " << j << endl;
                break;
            }
            cin >> a; j++;
            if(a < k){
                cout << i << " " << j-1 << endl;
                break;
            }
        }
        j++; i = j;
    }
    return 0;
}