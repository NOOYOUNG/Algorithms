#include <iostream>
using namespace std;

int main() {
  int a, b;
  string answer;

  cin>>a>>b;

  while(a!=0 && b!=0) {
    if(b%a==0){
      answer="factor";
    }
    else if(a%b==0){
      answer="multiple";
    }
    else {
      answer="neither";
    }
    
    cout<<answer<<endl;

    cin>>a>>b;
  }

  return 0;
}