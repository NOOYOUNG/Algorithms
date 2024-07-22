#include <iostream>
using namespace std;

int main() {
  int n;
  int array[10000];
  int j=0;
  
  while(1){
    cin>>n;
    if(n==-1) break;
    
    for(int i=1; i<n; i++){
      if(n%i==0){
        array[j]=i;
        j++;
      }
    }

    int sum=0;
    for(int i=0; i<j; i++){
      sum+=array[i];
    }

    if(sum==n) {
      cout<<n<<" = ";
      for(int i=0; i<j-1; i++){
        cout<<array[i]<<" + ";
      }
      cout<<array[j-1]<<endl;
    }
    else {
      cout<<n<<" is NOT perfect."<<endl;
    }

    j=0;
    sum=0;
    for(int i=0; i<j; i++){
      array[i]=0;
    }
  }
}