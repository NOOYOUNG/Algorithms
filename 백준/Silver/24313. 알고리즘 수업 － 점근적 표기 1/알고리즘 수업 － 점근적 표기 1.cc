#include <iostream>
using namespace std; 

int main()
{
  int a0, a1, n, c;
  cin>>a1>>a0;
  cin>>c;
  cin>>n;

  int fn=a1*n+a0;
  int gn=c*n;

  if(fn<=gn && a1<=c){
    cout<<1;
  }
  else{
    cout<<0;
  }
}