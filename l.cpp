#include <iostream>
#include <unordered_map>
using namespace std;
#include <vector>
typedef long long ll;
ll fact(ll n, ll res = 1){
    if(n<=1) return res;
    return fact(n-1, res *= n);
}
int main(){
    ll n; cin >> n;
    vector<vector<ll>> h;
    vector<vector<ll>> v;
    while(n--){
        ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        if(x1==x2){
            v.push_back({x1,min(y1,y2),max(y1,y2)});
        }else{
            h.push_back({y1,min(x1,x2),max(x1,x2)});
        }
    }
    ll count = 0;
    // combine overlaps
    for(ll i = 0; i < v.size()-1; ++i){
        for(ll j = i + 1; j < v.size(); ++j){
            vector<ll> v1 = v[i];
            vector<ll> v2 = v[j];
            if(v1[0]!=v2[0])continue;
            if(v1[1]>v2[2] || v2[1]>v1[2]) continue;
            ll r1 = min(v1[1],v2[1]);
            ll r2 = max(v1[2],v2[2]);
            v.push_back({v1[0],r1,r2});
            v.erase(v.begin()+i, v.begin()+j);
        }
    }
    // combine overlaps
    for(ll i = 0; i < h.size()-1; ++i){
        for(ll j = i + 1; j < h.size(); ++j){
            vector<ll> h1 = h[i];
            vector<ll> h2 = h[j];
            if(h1[0]!=h2[0])continue;
            if(h1[1]>h2[2] || h2[1]>h1[2]) continue;
            ll r1 = min(h1[1],h2[1]);
            ll r2 = max(h1[2],h2[2]);
            h.push_back({h1[0],r1,r2});
            h.erase(h.begin()+i, h.begin()+j);
        }
    }
    // itr vertical combos
    for(ll i = 0; i < v.size()-1; ++i){
        for(ll j = i + 1; j < v.size(); ++j){
            vector<ll> v1 = v[i];
            vector<ll> v2 = v[j];
            ll r1 = max(v1[1],v2[1]);
            ll r2 = min(v1[2],v2[2]);
            if(r2-r1<=0)continue;
            ll d1 = min(v1[0],v2[0]);
            ll d2 = max(v1[0],v2[0]);
            // itr horizontal combos
            ll cnt = 0;
            for(ll k = 0; k < h.size(); ++k){
                vector<ll> h1 = h[k];

                if(h1[1]<=d1 && h1[2]>=d2 && (h1[0]>=r1&&h1[0]<=r2))cnt++;
            }
            count += (fact(cnt) / (fact(2)*fact(cnt-2)));
        }
    }
    cout << count << endl;
    return 0;
}