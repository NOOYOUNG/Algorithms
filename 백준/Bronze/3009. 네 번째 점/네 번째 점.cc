#include <iostream>
using namespace std;

int main() {
  int xarr[3];
  int yarr[3];

  for(int i=0; i<3; i++){
    cin>>xarr[i]>>yarr[i];
  }

  if(xarr[0]==xarr[1]){
    cout<<xarr[2];
  }
  else if(xarr[0]==xarr[2]){
    cout<<xarr[1];
  }
  else if(xarr[1]==xarr[2]){
    cout<< xarr[0];
  }

  cout<<" ";
  
  if(yarr[0]==yarr[1]){
    cout<<yarr[2];
  }
  else if(yarr[0]==yarr[2]){
    cout<<yarr[1];
  }
  else if(yarr[1]==yarr[2]){
    cout<< yarr[0];
  }

  return 0;
  
}