#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer;
    int dp[501][501]={0};
    
    for (int i = 0; i < triangle.size(); i++) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] = triangle[i][j];
        }
    }
    
    for(int i=triangle.size()-2; i>=0; i--){
        for(int j=0; j<=i; j++){
            dp[i][j]+=max(dp[i+1][j], dp[i+1][j+1]);
        }
    }

    answer=dp[0][0];
    return answer;
}