#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> tree; // 세그먼트 트리를 저장할 벡터
vector<long long> arr;  // 원본 배열을 저장할 벡터

// 세그먼트 트리 구축 함수
void buildTree(int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];  // 리프 노드는 단일 요소를 가짐
    } else {
        int mid = (start + end) / 2;
        buildTree(2 * node, start, mid);         // 왼쪽 자식 노드 구축
        buildTree(2 * node + 1, mid + 1, end);   // 오른쪽 자식 노드 구축
        tree[node] = tree[2 * node] + tree[2 * node + 1];  // 내부 노드는 두 자식의 합
    }
}

// 세그먼트 트리 업데이트 함수
void updateTree(int node, int start, int end, int idx, long long val) {
    if (start == end) {
        arr[idx] = val;  // 원본 배열의 값을 업데이트
        tree[node] = val;  // 세그먼트 트리의 해당 노드도 업데이트
    } else {
        int mid = (start + end) / 2;
        if (idx <= mid) {
            updateTree(2 * node, start, mid, idx, val);  // 왼쪽 자식 노드 업데이트
        } else {
            updateTree(2 * node + 1, mid + 1, end, idx, val);  // 오른쪽 자식 노드 업데이트
        }
        tree[node] = tree[2 * node] + tree[2 * node + 1];  // 내부 노드 업데이트
    }
}

// 세그먼트 트리 쿼리 함수
long long queryTree(int node, int start, int end, int L, int R) {
    if (R < start || end < L) {
        return 0;  // 노드의 범위가 요청한 범위와 완전히 겹치지 않음
    }
    if (L <= start && end <= R) {
        return tree[node];  // 노드의 범위가 요청한 범위에 완전히 포함됨
    }
    int mid = (start + end) / 2;
    long long sumLeft = queryTree(2 * node, start, mid, L, R);  // 왼쪽 자식 쿼리
    long long sumRight = queryTree(2 * node + 1, mid + 1, end, L, R);  // 오른쪽 자식 쿼리
    return sumLeft + sumRight;  // 두 부분의 합을 반환
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    arr.resize(N + 1); // 원본 배열 크기 설정
    tree.resize(4 * N); // 세그먼트 트리 크기 설정

    for (int i = 1; i <= N; i++) {
        cin >> arr[i]; // 원본 배열 입력
    }

    buildTree(1, 1, N);  // 세그먼트 트리 구축

    for (int i = 0; i < M + K; i++) {
        long long a, b, c;
        cin >> a >> b >> c;

        if (a == 1) {
            updateTree(1, 1, N, b, c);  // b 인덱스의 값을 c로 업데이트
        } else if (a == 2) {
            cout << queryTree(1, 1, N, b, c) << '\n';  // b부터 c까지의 합을 출력
        }
    }

    return 0;
}
