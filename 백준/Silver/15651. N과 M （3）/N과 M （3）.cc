#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
int N, M;

void dfs(int cnt){
  if(cnt==M){
    for(int i=0; i<M; i++)
      cout<<arr[i]<<' ';
    cout<<'\n';
  }
  else{
    for(int i=1; i<=N; i++){
      arr.push_back(i);
      dfs(cnt+1);
      arr.pop_back();
    }
  }
}

int main(){
  cin>>N>>M;
  dfs(0);
  return 0;
}