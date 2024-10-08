#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    int N=board.size();
    int M=board[0].size();
    
    vector<vector<int>> build(N+1, vector<int>(M+1,0));
    
    for(int i=0; i<skill.size(); i++){
        int r1=skill[i][1];
        int c1=skill[i][2];
        int r2=skill[i][3];
        int c2=skill[i][4];
        int degree=skill[i][5];
        
        if(skill[i][0]==1){
            degree=(-degree);
        }

        build[r1][c1]+=degree;
        build[r1][c2+1]-=degree;
        build[r2+1][c1]-=degree;
        build[r2+1][c2+1]+=degree;
    }
    
    for(int i=0; i<N; i++){
        for(int j=1; j<M; j++){
            build[i][j]+=build[i][j-1];
        }
    }
    
    for(int j=0; j<M; j++){
        for(int i=1; i<N; i++){
            build[i][j]+=build[i-1][j];
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            board[i][j]+=build[i][j];
            if(board[i][j]>0) answer++;
        }
    }
    
    return answer;
}