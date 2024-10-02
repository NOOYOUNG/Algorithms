#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i=0; i<n; i++){
        string row="";
        int combined=arr1[i]|arr2[i];
        
        for(int j=n-1; j>=0; j--){
            if(combined & (1<<j)){
                row+="#";
            }
            else{
                row+=" ";
            }
        }
        answer.push_back(row);
    }
    
    return answer;
}