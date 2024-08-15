#include <iostream>
#include <vector>

using namespace std;

int main() {
  int w, h;
  int answer=0;
  cin>>h>>w;

  vector<int> block(w);
  for(int i=0; i<w; i++){
    cin>>block[i];
  }

  for(int i=1; i<w-1; i++){
    int left=0, right=0;

    for(int j=0; j<i; j++){
      left=max(left, block[j]);
    }
    for(int j=w-1; j>i; j--){
      right=max(right,block[j]);
    }
    answer+=max(0,min(left,right)-block[i]); //max하는 이유는 0보다 작을 수 없으니까
  }
  cout<<answer;
  return 0;
}