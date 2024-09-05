#include <iostream>

using namespace std;

int main(){
  int N;
  cin>>N;

  int bag=0;
  
  while(N>=0){
    if(N%5==0){
      bag+=(N/5);
      cout<<bag<<endl;
      return 0;      
    }
    N-=3;
    bag++;
  }

  cout<<-1; // 3kg 혹은 5kg의 합으로 만들 수 없는 경우
}