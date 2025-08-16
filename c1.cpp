#include <queue>
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int rows, cols, max; cin >> rows >> cols >> max;
    rows = (max-cols)/2+1;
    if(rows <= 0){
        cout << 0 << endl;
        return 0;
    }
    vector<vector<int>> g1(rows, vector<int>(cols,1));
    vector<vector<int>> g2(rows, vector<int>(cols,1));
    for(int row = 1; row < rows; ++row){
        for(int col = 1; col < cols; ++col){
            g1[row][col]=g1[row-1][col]+g1[row][col-1];
        }
    }
    int count = 0;
    for(int row = 1; row < rows; ++row){
        for(int col = cols-2; col >= 0; --col){
            int sum = g2[row-1][col]+g2[row][col+1];
            g2[row][col]=g2[row-1][col]+g2[row][col+1];
            count += sum * g1[row][col];
        }
    }
    cout << count + rows << endl;
    return 0;
}