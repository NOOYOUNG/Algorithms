#include <iostream>
using namespace std;

int arr[21];
int N, S;
int ans = 0;

void dfs(int index, int sum) {
    if (index == N) { // 배열의 모든 원소를 고려한 상태
        if (sum == S) {
            ans++;
        }
        return;
    }
  
    // 현재 원소를 포함시키는 경우
    dfs(index + 1, sum + arr[index]);

    // 현재 원소를 포함시키지 않는 경우
    dfs(index + 1, sum);
}

int main() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    dfs(0, 0);

    // 빈 집합의 경우 S가 0일 때를 별도로 고려해야 할 수 있음
    if (S == 0) {
        ans--;  // 빈 집합이 고려된 경우, 빈 집합을 포함한 경우를 제외하기 위해 ans를 감소
    }

    cout << ans << endl;
    return 0;
}
