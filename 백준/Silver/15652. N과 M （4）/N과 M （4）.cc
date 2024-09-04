#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
int N, M;

void dfs(int cnt, int start){
  if(cnt==M){
    for(int i=0; i<M; i++)
      cout<<arr[i]<<' ';
    cout<<'\n';
  }
  else{
    for(int i=start; i<=N; i++){
      arr.push_back(i);
      dfs(cnt+1, i);
      arr.pop_back();
    }
  }
}

int main(){
  cin>>N>>M;
  dfs(0, 1);
  return 0;
}