#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin>>N;

  if(N==1) return 0; //N이 1인 경우 아무것도 출력하지 않는다.

  for(int i=2; i<=N; i++){
    while(N%i==0){
      cout<<i<<endl;
      N=N/i;
    }
  }
}