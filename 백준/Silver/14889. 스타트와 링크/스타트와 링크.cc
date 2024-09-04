#include <iostream>
#include <cmath>
using namespace std;

int N;
int stat[21][21];
bool check[22];
int ans=100000000;

void dfs(int cnt, int idx){
  if(cnt==N/2){
    int start=0;
    int link=0;

    for(int i=1; i<=N; i++){
      for(int j=1; j<=N; j++){
        if(check[i]==true && check[j]==true) start+=stat[i][j];
        if(check[i]==false && check[j]==false) link+=stat[i][j];
      }
    }
    int tmp=abs(start-link);
    if(ans>tmp) ans=tmp;
    return;
  }

  for(int i=idx; i<N; i++){
    check[i]=true;
    dfs(cnt+1, i+1);
    check[i]=false;
  }
}

int main(){
  cin>>N;
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
      cin>>stat[i][j];
    }
  }

  dfs(0, 1); //카운트 0부터, 숫자 1부터 시작
  cout<<ans;
}