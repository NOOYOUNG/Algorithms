#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    vector<int> days;
    
    for(int i=0; i<progresses.size(); i++){
        if((100-progresses[i])%speeds[i]==0){
            days.push_back((100-progresses[i])/speeds[i]);
        }
        else{
            days.push_back(((100-progresses[i])/speeds[i])+1);
        }
    }
    
    int cnt=0;
    int max=days[0];
    for(int i=0; i<days.size(); i++){
        if(days[i]<=max){
            cnt++;
        }
        else{
            answer.push_back(cnt);
            max=days[i];
            cnt=1;
        }
    }
    answer.push_back(cnt);
    
    return answer;
}