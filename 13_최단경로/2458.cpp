#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 500; // 학생 수의 최대 값
const int INF = 1e9; // 무한대를 나타내기 위한 큰 값

int n, m; // 학생 수, 키 비교 횟수
int dist[MAX_N + 1][MAX_N + 1]; // 학생 간의 최단 경로 거리 배열

// 플로이드-워셜 알고리즘을 이용하여 모든 쌍 최단 경로 계산
void floyd_warshall() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

// 자신이 키가 몇 번째인지 알 수 있는 학생의 수를 계산하는 함수
int count_known_ranks() {
    int known_ranks = 0;

    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] != INF || dist[j][i] != INF) {
                count++;
            }
        }
        if (count == n) {
            known_ranks++;
        }
    }

    return known_ranks;
}

int main() {
    cin >> n >> m; // 학생 수와 키 비교 횟수 입력

    // 거리 배열 초기화
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = INF;
            }
        }
    }

    // 인접 행렬로 도로 정보 입력
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dist[a][b] = 1; // a번 학생이 b번 학생보다 키가 작음을 의미
    }

    // 플로이드-워셜 알고리즘 적용
    floyd_warshall();

    // 키 순위를 확실히 알 수 있는 학생 수 계산 및 출력
    cout << count_known_ranks() << endl;

    return 0;
}
