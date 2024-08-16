#include <string>
#include <vector>

using namespace std;

bool visited[9];
int answer=0;

void DFS(int cnt, int k, vector<vector<int>> dungeons){
    answer=max(answer, cnt);
    
    for(int i=0; i<dungeons.size(); i++){
        if(!visited[i] && k>=dungeons[i][0]){
            visited[i]=true;
            DFS(cnt+1, k-dungeons[i][1], dungeons);
            visited[i]=false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    DFS(0, k, dungeons);
        
    return answer;
}