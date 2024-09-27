#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end());
    int n=citations.size();
    
    for(int h=n; h>0; h--){
        if(citations[n-h]>=h){
            answer=h;
            break;
        }
    }
        
    return answer;
}