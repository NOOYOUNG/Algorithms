#include <iostream>
using namespace std;

int main(){
  int N;
  cin>>N;
  int arr[1001];
  int dp[1001]={0,};
  
  for(int i=0; i<N; i++){
    cin>>arr[i];
    dp[i]=1;
  }

  for(int i=0; i<N; i++){
    for(int j=0; j<i; j++){
      if(arr[i]>arr[j]){
        dp[i]=max(dp[j]+1, dp[i]);
      }
    }
  }

  int ans=0;
  for(int i=0; i<N; i++){
    ans=max(ans, dp[i]);
  }

  cout<<ans;
}