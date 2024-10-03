#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    
    vector<int> scores;
    int idx=0;
    
    for(int i=0; i<dartResult.size(); i++){
        if(isdigit(dartResult[i])){
            int score=dartResult[i]-'0';
            
            if(i+1<dartResult.size() && isdigit(dartResult[i+1])){ // 두 자리 수
                score=score*10+(dartResult[i+1]-'0');
                i++;
            }
            scores.push_back(score);
            idx++;
        }
        else if(dartResult[i]=='S'){
            scores[idx-1]=pow(scores[idx-1], 1);
        }
        else if(dartResult[i]=='D'){
            scores[idx-1]=pow(scores[idx-1], 2);
        }
        else if(dartResult[i]=='T'){
            scores[idx-1]=pow(scores[idx-1], 3);
        }
        else if(dartResult[i]=='*'){
            scores[idx-1]*=2;
            if(idx>1){
                scores[idx-2]*=2;
            }
        }
        else if(dartResult[i]=='#'){
            scores[idx-1]*=(-1);
        }
    }
    
    for(auto s:scores){
        answer+=s;
    }
    
    return answer;
}