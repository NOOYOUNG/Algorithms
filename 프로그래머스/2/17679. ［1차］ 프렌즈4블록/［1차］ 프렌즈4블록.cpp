#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    vector<vector<bool>> isSquare(m, vector<bool>(n, false));
    bool remove=false;
    
    do{
        for (int i = 0; i < isSquare.size(); i++){
            fill(isSquare[i].begin(), isSquare[i].end(), false);   
        }
        remove = false;
        
        // 2x2 정사각형 블록을 찾아 기록
        for(int i=0; i<m; i++){ // 각 행을 반복
            for(int j=0; j<n; j++){ // 각 열을 반복
                // 첫 행 또는 첫 열은 2x2 정사각형이 불가능하므로 skip
                // board[i][j]가 '0'이라면 이미 삭제된 블록이므로 skip
                if(i==0 || j==0 || board[i][j]=='0'){
                    continue;
                }
                
                if((board[i-1][j-1]==board[i][j-1]) && (board[i-1][j-1]==board[i-1][j]) && (board[i-1][j-1]==board[i][j])){
                    isSquare[i][j]=true;
                    isSquare[i-1][j]=true;
                    isSquare[i][j-1]=true;
                    isSquare[i-1][j-1]=true;
                    remove=true;
                }
            }
        }
        
        // 2x2 블록 없애기
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(isSquare[i][j]){
                    board[i][j]='0';
                    answer++;
                }
            }
        }
        
        // 블록 떨어뜨리기 (두 번째 행부터 시작)
        for(int i=1; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='0'){
                    for(int k=i; k>0; k--){
                        if(board[k-1][j]=='0') break;
                        board[k][j]=board[k-1][j];
                        board[k-1][j]='0';
                    }
                }
            }
        }
    } while(remove);
    
    return answer;
}