#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9; // 무한대 값을 나타내기 위한 상수
const int MAX_N = 1000; // 마을의 최대 개수
const int MAX_M = 10000; // 도로의 최대 개수

struct Edge {
    int to, time;
};

vector<Edge> adj[MAX_N + 1]; // 각 마을에 대한 인접 리스트
int n, m, x; // 마을의 개수, 도로의 개수, 파티가 열리는 마을

// 다익스트라 알고리즘을 이용하여 최단 시간을 계산하는 함수
vector<int> dijkstra(int start) {
    vector<int> dist(n + 1, INF); // 거리를 무한대로 초기화
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 최소 힙

    dist[start] = 0; // 시작점의 거리는 0
    pq.push({0, start}); // 시작점을 힙에 추가

    while (!pq.empty()) {
        int curr_dist = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if (curr_dist > dist[curr]) {
            continue; // 이미 처리된 경우 무시
        }

        for (const auto& edge : adj[curr]) {
            int next = edge.to;
            int next_dist = curr_dist + edge.time;

            if (next_dist < dist[next]) {
                dist[next] = next_dist;
                pq.push({next_dist, next});
            }
        }
    }

    return dist; // 각 정점까지의 최단 거리 반환
}

int main() {
    cin >> n >> m >> x;

    for (int i = 0; i < m; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        adj[u].push_back({v, t}); // 인접 리스트에 도로 정보 추가
    }

    // 파티 마을에서 모든 마을로의 최단 거리
    vector<int> dist_from_x = dijkstra(x);

    int max_time = 0;

    // 모든 마을에서 파티 마을로의 최단 거리 계산 및 최대 시간 계산
    for (int i = 1; i <= n; i++) {
        if (i == x) {
            continue; // 파티 마을은 건너뛰기
        }
        vector<int> dist_to_x = dijkstra(i);
        max_time = max(max_time, dist_to_x[x] + dist_from_x[i]);
    }

    cout << max_time << endl;

    return 0;
}
