#include <queue>
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int row, col, max; cin >> row >> col >> max;
    int downMax = (max-col)/2;
    // first segment bfs
    queue<pair<int,int>> q1;
    queue<pair<int,int>> q2;
    q1.push({0,0});
    while(!q1.empty()){
        int x = q1.front().first;
        int y = q1.front().second; q1.pop();
        if(y==downMax){
            q2.push({x, y});
            continue;
        }
        if(x==col-1){
            q2.push({x,y});
            q1.push({x,y+1});
            continue;
        }
        q1.push({x+1,y});
        q1.push({x,y+1});
    }
    // second segment bfs
    int count = 0;
    while(!q2.empty()){
        int x = q2.front().first;
        int y = q2.front().second; q2.pop();
        if(x==col-1){
            count++;
            continue;
        }
        if(y==0){
            q2.push({x+1,y});
            continue;
        }
        q2.push({x+1, y});
        q2.push({x, y-1});
    }
    cout << count << endl;
    return 0;
}