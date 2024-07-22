#include <iostream>
using namespace std;

int main() {
  int N, K;
  cin>>N>>K;

  int cnt=0;
  int array[10000];
  int j=0;
  for(int i=1; i<=N; i++){
    if(N%i==0){
      cnt++;
      array[j]=i;
      j++;
    }
  }
  
  if(cnt<K){
    cout<<0;
  }
  else{
    cout<<array[K-1];
  }

  return 0;
}