#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, int> m;
    
    for(auto p:clothes){ // p[옷의종류, 카테고리(개수)]
        m[p[1]]++;
    }
    
    for(auto p:m){
        answer*=(p.second+1);
    }
    
    return answer-1;
}