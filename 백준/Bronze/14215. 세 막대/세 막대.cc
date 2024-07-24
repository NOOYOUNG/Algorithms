#include <iostream>
#include <algorithm>
using namespace std; 

int main()
{
  int a, b, c;

  cin>>a>>b>>c;

  int arr[3]={a, b, c};
  sort(arr, arr+3);

  if(arr[0]+arr[1]>arr[2]){
    cout<<arr[0]+arr[1]+arr[2];
  }
  else{ //가장 긴 변의 길이가 나머지 두변의 합보다 작아야 한다.
    cout<<2*(arr[0]+arr[1])-1; // c=a+b-1 로 조절! 최댓값을 구하기 위함.
  }
}