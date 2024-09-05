#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int N;
  cin>>N;

  vector<int> dp(N+1);

  dp[1]=0; //1을 1로 만드는데 필요한 횟수 0회

  for(int i=2; i<=N; i++){
    // 1을 빼는 연산
    dp[i]=dp[i-1]+1;

    // 2로 나누는 연산
    if(i%2==0){
      dp[i]=min(dp[i], dp[i/2]+1);
    }
    
    // 3으로 나누는 연산
    if(i%3==0){
      dp[i]=min(dp[i], dp[i/3]+1);
    }
  }

  cout<<dp[N];

}