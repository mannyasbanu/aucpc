#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
int main(){
    ll n; cin >> n;
    queue<pair<ll,ll>> wines;
    ll redCount = 0;
    ll whiteCount = 0;
    ll count = 0;
    ll max = 0;
    while(n--){
        ll red, white; cin >> red >> white;
        if(wines.empty() && red > white) continue;
        wines.push({red,white});
        redCount += red;
        whiteCount += white;
        while(!wines.empty() && redCount > whiteCount){
            redCount -= wines.front().first;
            whiteCount -= wines.front().second;
            wines.pop();
        }
        count = whiteCount + redCount;
        if(count > max) max = count;
    }
    cout << max << endl;
    return 0;
}