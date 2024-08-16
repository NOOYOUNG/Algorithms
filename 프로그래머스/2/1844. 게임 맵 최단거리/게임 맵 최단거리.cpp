#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}}; // 상하좌위 이동방향
bool visited[101][101]; // 방문여부 체크
int dist[101][101]; // 각셀까지 최단거리 저장
queue<pair<int,int>> q;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    n=maps.size();
    m=maps[0].size();
    
    memset(visited, false, sizeof(visited)); // 방문배열 false 초기화
    memset(dist, 0, sizeof(dist)); // 최단거리배열 0 초기화
    
    visited[0][0]=true; // 시작지점 방문처리
    q.push({0,0}); // 큐에 시작지점 추가
    dist[0][0]=1; // 시작지점 거리 1 
    
    while(!q.empty()){
        int x=q.front().first; // 큐에서 현재위치 x좌표
        int y=q.front().second; // 큐에서 현재위치 y좌표
        q.pop(); // 큐에서 현재 위치 제거
        
        for(int i=0; i<4; i++){
            int nx=x+dir[i][0]; // 이동 후 x좌표
            int ny=y+dir[i][1]; // 이동 후 y좌표
            
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue; // 좌표가 맵의 범위 벗어나면 무시
        
            if(visited[nx][ny] || maps[nx][ny]==0) continue; // 방문한좌표or벽이면 무시
        
            visited[nx][ny]=true;
            q.push({nx, ny});
            dist[nx][ny]=dist[x][y]+1;
        }
    }
    
    if(dist[n-1][m-1]==0) // 도착지점에 도달할 수 없는 경우
        answer=-1; 
    else
        answer=dist[n-1][m-1];
    
    return answer;
}