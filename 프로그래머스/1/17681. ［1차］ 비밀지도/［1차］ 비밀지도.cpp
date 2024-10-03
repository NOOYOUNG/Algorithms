#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i=0; i<n; i++){
        string row="";
        int combined=arr1[i]|arr2[i]; // 비트 연산시 자동으로 이진화
        
        for(int j=n-1; j>=0; j--){ // 맨오른쪽부터 계산
            if(combined & (1<<j)){ // combined의 j번째 비트가 1인지 확인 -> 1이면 참, 0이면 거짓
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