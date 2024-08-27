#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> nocomplt;
    
    for(auto p:participant){ // 전체 명단 숫자 +1
        nocomplt[p]++;
    }
    
    for(auto c:completion){ // 완주하면 숫자 -1
        nocomplt[c]--;
    }
    
    for(auto n:nocomplt){ 
        if(n.second>0){ // 숫자가 0보다 크면 완주 못한 것
            answer=n.first; //hash의 string 출력
        }
    }
    
    return answer;
}