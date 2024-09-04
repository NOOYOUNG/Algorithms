#include <iostream>
#include <vector>
#include <cmath> // abs 함수 사용을 위한 헤더

using namespace std;

int N;
vector<int> board;

bool isSafe(int row, int col) { // 현재 위치에 퀸을 놓아도 되는지 확인
    for (int i = 0; i < row; i++) {
        // 같은 열에 퀸이 있는지 같은 대각선에 퀸이 있는지 확인
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void solveNQueens(int row, int &cnt) {
    if (row == N) { // 모든 행에 퀸을 배치한 경우
        cnt++;
        return;
    }
    for (int col = 0; col < N; col++) { // 현재 행의 모든 열에 대해 반복
        if (isSafe(row, col)) { // 현재 위치에 퀸을 놓을 수 있는지 확인
            board[row] = col; // 현재 행의 열에 퀸을 놓음
            solveNQueens(row + 1, cnt);; // 다음 행에 대해 재귀 호출
        }
    }
}

int main() {
    cin >> N;
    board.resize(N, -1); // N을 알고 나서 벡터 크기 설정

    int cnt = 0;
    solveNQueens(0, cnt);

    cout << cnt << endl;
    return 0;
}