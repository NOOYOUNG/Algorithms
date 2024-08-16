#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    vector<int> days;
    for(int i=0; i<progresses.size(); i++){
        int a=0;
        if((100-progresses[i])%speeds[i]==0){
            a=(100-progresses[i])/speeds[i];
        }
        else{
            a=(100-progresses[i])/speeds[i]+1;
        }
        days.push_back(a);
    }
    
    queue<int> q;
    int max=days[0];
    int cnt=0;
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