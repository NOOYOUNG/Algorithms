#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<int> arr;
    
    while(n>=3){
        arr.push_back(n%3);
        n=n/3;
    }
    
    arr.push_back(n);
    
    for(int i=0; i<arr.size(); i++){
        answer+=arr[i]*pow(3,arr.size()-1-i);
    }
    return answer;
}