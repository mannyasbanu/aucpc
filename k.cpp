#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    string p = "PEACE";
    int itr = 0;
    for(size_t i = 0; i < n; i++){
        char c;
        cin >> c;
        if(c == p[itr]) itr++;
        if(itr > 4){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}