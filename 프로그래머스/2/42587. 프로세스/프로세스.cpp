#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<pair<int, int>> que;
    priority_queue<int> pq;
    
    for(int i=0; i<priorities.size(); i++){
        que.push(make_pair(i, priorities[i]));
        pq.push(priorities[i]); // 우선순위 자동 정렬
    }
    
    while(!que.empty()){ // 큐에 값이 있는 동안
        int i=que.front().first;
        int pNum=que.front().second;
        que.pop();
        
        if(pNum==pq.top()){ // 현재 큐의 가장 앞에 있는 프로세스가 최고 우선순위인지 확인
            answer++;
            pq.pop();
            
            if(i==location){
                break;
            }
        }
        else{
            que.push(make_pair(i, pNum));
        }
    }
    
    return answer;
}