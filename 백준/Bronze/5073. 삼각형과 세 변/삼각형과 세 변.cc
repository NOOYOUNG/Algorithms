#include <iostream> 
#include <algorithm>
#include <vector>
using namespace std; 

int main()
{
  int a, b, c;

  while(true){
    cin>>a>>b>>c;

    if(a==0 && b==0 && c==0){
      break;
    }
    
    int arr[3]={a, b, c};
    sort(arr, arr+3);

    if(arr[2]>=arr[0]+arr[1]){
      cout<<"Invalid"<<endl;
    }
    else if(a==b && b==c){
      cout<<"Equilateral"<<endl;
    }
    else if(a==b || b==c || a==c){
      cout<<"Isosceles"<<endl;
    }
    else{
      cout<<"Scalene"<<endl;
    }
  }

  return 0;
}