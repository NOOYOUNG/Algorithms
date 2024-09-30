#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int graph[20001];
bool visited[20001];
queue<int> q;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    memset(visited, false, sizeof(visited));
    memset(graph, 0, sizeof(graph));
    
    q.push(1); // 시작 노드(1)를 큐에 추가
    
    while(!q.empty()){
        int loc=q.front(); // 현재 노드
        q.pop();
        visited[loc]=true;
        
        for(int i=0; i<edge.size(); i++){
            // 현재 노드에서 연결된 노드
            if(edge[i][0]==loc && !visited[edge[i][1]]){
                q.push(edge[i][1]); // 연결된 노드를 큐에 추가
                graph[edge[i][1]]=graph[loc]+1;
                visited[edge[i][1]]=true;
            }
            else if(edge[i][1]==loc && !visited[edge[i][0]]){
                q.push(edge[i][0]);
                graph[edge[i][0]]=graph[loc]+1;
                visited[edge[i][0]]=true;
            }
        } 
    }
    
    // graph 시작부터 끝까지 가장 큰 값 찾음
    int max=*max_element(graph, graph+n);
    for(int i=1; i<=n; i++){
        if(max==graph[i]){
            answer++;
        }
    }
    
    return answer;
}