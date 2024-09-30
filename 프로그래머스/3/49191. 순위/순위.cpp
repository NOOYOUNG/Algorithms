#include <string>
#include <vector>
#include <queue>

using namespace std;

bool win[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    for(auto result:results){
        int winner=result[0];
        int loser=result[1];
        win[winner][loser]=true;
    }
    
    for(int k=1; k<=n; k++){ // 경유 노드
        for(int i=1; i<=n; i++){ // 시작 노드
            for(int j=1; j<=n; j++){ // 도착 노드
                if(win[i][k] && win[k][j])
                    win[i][j]=true; // i가 k를 이기고 k가 j를 이기면 i는 j를 이김
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        int cnt=0; // i와 관계를 아는 선수 수
        for(int j=1; j<=n; j++){
            if(win[i][j] || win[j][i])
                cnt++; // i와 j의 관계를 알고 있음
        }
        if(cnt==n-1) // n-1명 선수와 관계를 알면 정확히 랭크 가능
            answer++;
    }
    return answer;
}