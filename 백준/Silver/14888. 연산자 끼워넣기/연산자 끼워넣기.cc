#include <iostream>
using namespace std;

int N;
int arr[11];
int op[4];
int vmax=-1000000001, vmin=1000000001;

void getaswr(int result, int idx){
  if(idx==N){
    if(result>vmax){
      vmax=result;
    }
    if(result<vmin){
      vmin=result;
    }
    return;
  }

  for(int i=0; i<4; i++){
    if(op[i]>0){
      op[i]--;
      if(i==0){
        getaswr(result+arr[idx], idx+1);
      }
      else if(i==1){
        getaswr(result-arr[idx], idx+1);
      }
      else if(i==2){
        getaswr(result*arr[idx], idx+1);
      }
      else{
        getaswr(result/arr[idx], idx+1);
      }
      op[i]++; 
    }
  }
  return;
}

int main(){
  cin>>N;
  for(int i=0; i<N; i++){
    cin>>arr[i];
  }

  for(int i=0; i<4; i++){
    cin>>op[i];
  }

  getaswr(arr[0], 1);

  cout<<vmax<<endl;
  cout<<vmin;  
}