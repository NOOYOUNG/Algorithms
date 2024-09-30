#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;
bool visited[10001];
bool check=false; // 모든 항공권을 사용했는지 확인

void dfs(string airport, vector<vector<string>> tickets, int cnt){
    if(cnt==tickets.size()){ // 모든 항공권을 사용했다면
        check=true; // 사용 완료
    }
    answer.push_back(airport); // 현재 공항을 경로에 추가
    
    for(int i=0; i<tickets.size(); i++){
        // 현재 공항에서 출발하는 항공권을 찾고, 사용하지 않았다면
        if(!visited[i] && tickets[i][0]==airport){
            visited[i]=true;
            dfs(tickets[i][1], tickets, cnt+1); // 다음 공항으로 DFS 호출
            
            if(!check){ // 현재 공항에서 더 이상 사용할 항공권이 없을 때 
                answer.pop_back();
                visited[i]=false;
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    dfs("ICN", tickets, 0); // "ICN"에서 DFS 시작
    return answer;
}