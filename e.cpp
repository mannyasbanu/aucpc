#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;
struct Room {
    vector<Room*> links;
    int num;
};
int search(Room* room, set<int> &searched, int last){
    int count = 0;
    // single child
    while(room->links.size() <= 2){
        int rNum = room->num;
        if(searched.count(rNum)) return 0;
        else searched.insert(rNum);
        if(room->links[0]->num == last) room = room->links[1];
        else room = room->links[0];
        last = rNum;
        count ++;
        if(room->num == 1) return count;
    }
    // no children
    if(room->links.size() <= 0) return 0;
    // multiple children
    int found = 0;
    int countAdd = 0;
    for(int i = 0; i < room->links.size(); i++){
        int res = search(room->links[i], searched, room->num);
        if(res){
            found ++;
            countAdd = res;
        }
    }
    if(found > 1) return count;
    if(found == 1) return count += countAdd;
    if(found <= 0) return count;
    return 0;
}
int main(){
    // create graph
    int r, p;
    cin >> r >> p;
    unordered_map<int,Room*> rooms;
    for(int i = 1; i <= p; i++){
        int r1, r2;
        cin >> r1 >> r2;
        if(!rooms.count(r1)){
            rooms[r1] = new Room;
            rooms[r1]->num = r1;
        }
        if(!rooms.count(r2)){
            rooms[r2] = new Room;
            rooms[r2]->num = r2;
        }
        rooms[r1]->links.push_back(rooms[r2]);
        rooms[r2]->links.push_back(rooms[r1]);
    }
    // search starting at n
    set<int> searched;
    cout << search(rooms[p], searched, p) << endl;
}