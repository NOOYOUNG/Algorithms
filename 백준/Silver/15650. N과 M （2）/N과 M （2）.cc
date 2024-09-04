#include <iostream>
using namespace std;

int arr[9]={0,};
bool visited[9]={false,};
int N, M;

void btracking(int cnt, int start){
  if(cnt==M){
    for(int i=0; i<M; i++){
      cout<<arr[i]<<' ';
    }
    cout<<endl;
  }
  for(int i=start; i<=N; i++){
    if(!visited[i]){
      visited[i]=true;
      arr[cnt]=i;
      btracking(cnt+1, i+1);
      visited[i]=false;
    }
  }
}

int main(){
  cin>>N>>M;
  btracking(0, 1);
  return 0;
}