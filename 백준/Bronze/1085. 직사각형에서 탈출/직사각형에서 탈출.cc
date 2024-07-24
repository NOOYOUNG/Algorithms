#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int x, y, w, h;

  cin>>x>>y>>w>>h;

  int mw=abs(w-x);
  int mh=abs(h-y);

  int minimum=min(min(x, mw), min(y, mh));

  cout<<minimum;
  return 0;
}