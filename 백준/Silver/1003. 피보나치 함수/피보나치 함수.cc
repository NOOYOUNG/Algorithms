#include <iostream>

using namespace std;


int main(){
  int T;
  cin>>T;

  int zero[41]={1,0,};
  int one[41]={0,1};
  
  for(int i=0; i<T; i++){
    int n;
    cin>>n;
    for(int j=2; j<=n; j++){
      zero[j]=zero[j-1]+zero[j-2];
      one[j]=one[j-1]+one[j-2];
    }
    cout<<zero[n]<<" "<<one[n]<<endl;
  }
}