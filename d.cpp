#include <iostream>
using namespace std;
#include <set>
int main(){
    // read dimensions
    int n, m;
    cin >> n >> m;
    // read no supernova
    int num;
    cin >> num;
    // store state
    set<int> rowExp;
    set<int> colExp;
    int irr = 0;
    // iterate supernovas
    for(int i = 0; i < num; i++){
        // read row and col
        int row,col;
        cin >> row >> col;
        // check if dup row or col
        if(rowExp.count(row) || colExp.count(col)){
            if(!rowExp.count(row)){
                irr += m - colExp.size();
                rowExp.insert(row);
            } else if (!colExp.count(col)){
                irr += n - rowExp.size();
                colExp.insert(col);
            }
        } else {
            irr += n + m - 1;
            irr += - rowExp.size() - colExp.size();
            rowExp.insert(row);
            colExp.insert(col);
        }
        cout << irr << endl;
    }
    return 0;
}