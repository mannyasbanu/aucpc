#include <queue>
#include <iostream>
#include <vector>
using namespace std;
int main(){
    //int rows, cols, max; cin >> rows >> cols >> max;
    int rows = 5; int cols = 5; int max = 7; 
    int downMax = (max-cols)/2;
    rows = downMax + 1;
    vector<vector<int>> g1(downMax+1, vector<int>(cols,1));
    vector<vector<int>> g2(downMax+1, vector<int>(cols,1));
    for(int row = 1; row < rows; ++row){
        for(int col = 1; col < cols; ++col){
            g1[row][col]=g1[row-1][col]+g1[row][col-1];
            cout << "a" << endl;
        }
            cout << "b" << endl;

    }
    int count = 0;
    for(int row = 1; row < rows; ++row){
        for(int col = cols-2; col >= 0; --col){
            int sum = g2[row-1][col]+g2[row][col+1];
            g2[row][col]=g2[row-1][col]+g2[row][col+1];
            count += sum * g1[row][col];
        }
    }
    for(int row = 0; row < rows; ++row){
        for(int col = 0; col < cols; ++col){
            cout << g1[row][col];
        }
        cout << endl;
    }for(int row = 0; row < rows; ++row){
        for(int col = 0; col < cols; ++col){
            cout << g2[row][col];
        }
        cout << endl;
    }
    cout << count + rows << endl;
    return 0;
}