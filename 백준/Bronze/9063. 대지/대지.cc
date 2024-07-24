#include <iostream> 
#include <algorithm>
#include <vector>
using namespace std; 

int main()
{
  int N;
  cin>>N;
  
  vector<int> xarr(N);
  vector<int> yarr(N);

  for(int i=0; i<N; i++){
    cin>>xarr[i]>>yarr[i];
  }

  if(N==1){
    cout<<0;
  }
  else{ 
    sort(xarr.begin(), xarr.end());
    sort(yarr.begin(), yarr.end());
  
    int w=xarr[N-1]-xarr[0];
    int h=yarr[N-1]-yarr[0];
  
    cout<<w*h;
  }

  return 0;
}