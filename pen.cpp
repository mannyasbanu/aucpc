#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
int main(){
  unordered_map<int,int>nums;
  int max=0;
  int maxSecond=0;
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    int num;
    cin>>num;
    if(!nums.count(num))nums[num]=1;
    else nums[num]++;
    if(num>max){
      maxSecond=max;
      max=num;
    }else if(num>maxSecond&&num!=max)maxSecond=num;
  }
  cout<<nums[maxSecond]<<endl;
  return 0;
}