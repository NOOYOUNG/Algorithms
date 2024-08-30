#include <string>
#include <vector>

using namespace std;

void dfs(vector<int> &numbers, int target, int sum, int n, int &total) {
    // 모든 숫자를 마친 경우
    if (n >= numbers.size()) {
        // 현재 합계가 목표값과 같은지 확인
        if (sum == target) total++;
        return;
    }
    
    // 현재 인덱스 n에 있는 숫자를 더한 후, 다음 인덱스 n+1으로 이동하여 다음 숫자 처리
    dfs(numbers, target, sum + numbers[n], n + 1, total);
    
    // 현재 인덱스 n에 있는 숫자를 뺀 후, 다음 인덱스 n+1으로 이동하여 다음 숫자 처리
    dfs(numbers, target, sum - numbers[n], n + 1, total);
}

int solution(vector<int> numbers, int target) {
    int total = 0; // 목표값을 만드는 경우의 수를 저장할 변수
    
    // 첫 번째 숫자를 더하는 경우와 빼는 경우 탐색 시작
    dfs(numbers, target, numbers[0], 1, total);
    dfs(numbers, target, -numbers[0], 1, total);
    
    return total; // 목표값을 만드는 경우의 수를 반환
}