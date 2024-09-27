#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q; // 다리 위에 있는 트럭의 무게를 저장할 큐
    int weightSum=0; // 현재 다리 위에 있는 트럭들의 총 무게를 저장하는 변수
    int i=0; // 현재 다리로 진입하려는 트럭의 인덱스를 저장하는 변수
    
    while(true){ // 모든 트럭이 다리를 건널 때까지 반복
        int currentWeight=truck_weights[i]; // 현재 다리로 진입하려는 트럭의 무게
        
        if(i==truck_weights.size()){ // 모든 트럭이 다리에 진입했을 경우
            answer+=bridge_length; // 마지막 트럭이 다리를 완전히 건너기 위한 시간 추가
            break;
        }
        
        if(q.size()==bridge_length){ // 다리 위에 있는 트럭의 수가 다리 길이와 같을 경우
            weightSum-=q.front(); // 가장 먼저 진입한 트럭의 무게를 총 무게에서 뺌
            q.pop(); // 가장 먼저 진입한 트럭을 큐에서 제거
        }
        
        if(weightSum+currentWeight<=weight){ // 현재 다리 위의 무게와 진입할 트럭의 무게를 더했을 때 다리의 최대 무게를 넘지 않으면
            weightSum+=currentWeight; // 현재 다리 위의 총 무게에 진입할 트럭의 무게를 더함
            q.push(currentWeight); // 트럭을 다리 위에 올림(큐에 추가)
            i++; // 다음 트럭을 준비하기 위해 인덱스 증가
        }
        else{
            q.push(0); // 만약 트럭이 다리 위에 올라갈 수 없다면 0을 큐에 넣어 트럭이 다리 위에서 한 칸씩 이동하도록 설정
        }
        
        answer++;
    }
    
    return answer;
}