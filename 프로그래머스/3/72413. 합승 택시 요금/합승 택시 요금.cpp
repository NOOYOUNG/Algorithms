#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;

// 다익스트라 알고리즘을 수행하는 함수
void dijkstra(int start, vector<int>& dist, const vector<vector<pair<int, int>>>& graph) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0; // 시작 노드의 거리를 0으로 초기화
    pq.push({0, start}); // 시작 노드 추가

    while (!pq.empty()) {
        int curDist = pq.top().first; // 현재 노드까지의 거리
        int curNode = pq.top().second; // 현재 노드
        pq.pop();

        // 현재 노드까지의 거리보다 큰 경우 무시
        if (curDist > dist[curNode]) continue;

        // 현재 노드와 연결된 모든 이웃 노드 확인
        for (const auto& g : graph[curNode]) {
            int adjNode = g.first; // 인접 노드
            int cost = g.second; // 비용

            // 새로운 거리 계산
            if (curDist + cost < dist[adjNode]) {
                dist[adjNode] = curDist + cost; // 거리 업데이트
                pq.push({dist[adjNode], adjNode}); // 새로운 거리와 노드를 큐에 추가
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INT_MAX;

    // 그래프 초기화
    vector<vector<pair<int, int>>> graph(n + 1);

    // 그래프에 간선 추가
    for (auto f : fares) {
        int start = f[0];
        int dest = f[1];
        int cost = f[2];
        graph[start].push_back({dest, cost}); // 양방향 간선 추가
        graph[dest].push_back({start, cost});
    }

    // 각 노드에 대한 거리 배열 초기화
    vector<int> distFromS(n + 1, INT_MAX);
    vector<int> distFromA(n + 1, INT_MAX);
    vector<int> distFromB(n + 1, INT_MAX);

    // s에서의 거리 계산
    dijkstra(s, distFromS, graph);
    // a에서의 거리 계산
    dijkstra(a, distFromA, graph);
    // b에서의 거리 계산
    dijkstra(b, distFromB, graph);

    // 최솟값 계산
    for (int i = 1; i <= n; i++) {
        answer = min(answer, distFromS[i] + distFromA[i] + distFromB[i]); // 각 경로의 비용 계산
    }

    return answer;
}