#include <iostream>
using namespace std;

int arr[9]={0,};
bool visited[9]={false,};
int N, M;

void btracking(int cnt, int start){
  if(cnt==M){
    for(int i=0; i<M; i++){
      cout<<arr[i]<<' '; // 현재 조합 출력
    }
    cout<<endl;
  }
  for(int i=start; i<=N; i++){ // `start`부터 시작하여 각 숫자를 고려
    if(!visited[i]){
      visited[i]=true;
      arr[cnt]=i;
      btracking(cnt+1, i+1); // 다음 숫자가 현재 숫자보다 더 커야 함
      visited[i]=false;
    }
  }
}

int main(){
  cin>>N>>M;
  btracking(0, 1); // 숫자 1부터 시작
  return 0;
}
