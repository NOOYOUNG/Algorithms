#include <iostream>
#include <vector>
using namespace std;

int main() {
  int M, N;
  cin>>M;
  cin>>N;

  vector<int> vec;

  for(int i=M; i<=N; i++){
    int cnt=0;
    for(int j=1; j<=i; j++){
      if(i%j==0){
        cnt++;
      }
    }
    if(cnt==2){
      vec.push_back(i);
    }
  }

  int sum=0;

  for(int i=0; i<vec.size(); i++){
    sum+=vec[i];
  }

  if(vec.size()==0){
    cout<<"-1";
  }
  else{
    cout<<sum<<endl<<vec[0];
  }
  
}