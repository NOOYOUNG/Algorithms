#include <iostream>
#include <vector>
using namespace std;

int main(){
  int T;
  cin>>T;
  
  for(int i=0; i<T; i++){
    int n;
    cin>>n;
    vector<int> dp(n+1, 0); // n+1개 배열 0으로 초기화

    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;

    for(int j=4; j<=n; j++){
      dp[j]=dp[j-1]+dp[j-2]+dp[j-3];
    }

    cout<<dp[n]<<endl;
  }
  
  return 0;  
}

/*
d[1] = 1
d[2] = 2
d[3] = 4
> n=4부터 시작
d[4] = 4+2+1 = 7
d[5] = 7+4+2 = 13
>> d[n] = d[n-1]+d[n-2]+d[n-3]
*/