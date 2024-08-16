#include <string>
#include <vector>

using namespace std;

bool visited[201];

void DFS(int current, int n, vector<vector<int>> coms){
    visited[current]=true;
    
    for(int i=0; i<n; i++){
        if(!visited[i] && coms[current][i]==1){
            DFS(i, n, coms); // 재귀 호출
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0; i<n; i++){
        if(!visited[i]) { // 방문하지 않았다면
            DFS(i, n, computers);
            answer++;
        }
    }
    
    return answer;
}