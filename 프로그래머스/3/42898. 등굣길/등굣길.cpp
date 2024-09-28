#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    long long road[101][101] = {0};
    
    for(auto p:puddles){
        road[p[0]][p[1]]=-1;
    }
    
    road[1][1]=1;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(road[i][j]==-1) continue;
            if(i>1 && road[i-1][j]!=-1){ // 위에서 이동
                road[i][j]+=road[i-1][j];
            }
            if(j>1 && road[i][j-1]!=-1){ // 왼쪽에서 이동
                road[i][j]+=road[i][j-1];
            }
            road[i][j]%=1000000007;
        }
    }
    
    answer=road[m][n]%1000000007;
    
    return answer;
}