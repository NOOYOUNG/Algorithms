#include <iostream>
using namespace std;

int main() {
  int N, num;
  cin>>N;

  int cnt=0;
  while(N--){
    cin>>num;
    bool prime=true;
    if(num==1) continue;
    for(int i=num-1; i>1; i--){
      if(num%i==0){
        prime=false;
        break;
      }
    }
    if(prime) cnt++;
  }
  cout<<cnt<<endl;
  return 0;
}