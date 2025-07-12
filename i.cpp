#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

int sol(vector<pair<int,int>> input){
    int low = 100001;
    // iterate each battery
    for(int i = 0; i < input.size()-1; i++){
        // read type
        int type = input[i].first;
        // find batterys ahead with same type
        for(int j = i+1; j < input.size(); j++){
            if(input[j].first == type){
                // calculate and update power
                int pow = abs(input[i].second - input[j].second);
                if(pow < low) low = pow;
                if(low == 1) return 1;
            }
        }
    }
    if(low == 100001) return -1;
    return low;
}

int solv2(unordered_map<int,vector<int>> input, vector<int> types){
    int low = 100001;
    for(int i = 0; i < types.size(); i++){
        vector<int> l = input[types[i]];
        for(int j = 0; j < l.size()-1; j++){
            int pow = abs(l[j]-l[j+1]);
            if(pow < low) low = pow;
            if(low == 1) return 1;
        }
    }
    if(low == 100001) return -1;
    return low;
}

int main(){
    // read inputs by mapping type
    unordered_map<int,vector<int>> input;
    vector<int> types;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int type;
        int pow;
        cin >> type >> pow;
        if(!input.count(type)) types.push_back(type);
        input[type].push_back(pow);
    }
    // sort vectors
    for(int i = 0; i < types.size(); i++){
        int t = types[i];
        sort(input[t].begin(), input[t].end());
    }
    cout << solv2(input, types) << endl;

    return 0;
}
