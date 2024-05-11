#include <iostream>
#include <vector>

const int MAX_SIZE = 50; // 최대 맵 크기 상수 정의
int map[MAX_SIZE][MAX_SIZE]; // 맵 데이터 저장 배열
int visited[MAX_SIZE][MAX_SIZE] = {0}; // 방문한 위치를 표시하는 배열
int clean_count = 0; // 청소한 칸의 수

// 방향 벡터 정의 (북, 동, 남, 서)
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

// 입력 처리 함수
void process_input(int& n, int& m, int& r, int& c, int& d) {
    std::cin >> n >> m;
    std::cin >> r >> c >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> map[i][j];
        }
    }
    visited[r][c] = 1;
    clean_count = 1;
}

// 로봇 청소기의 동작을 수행하는 DFS 함수
void perform_cleaning(int r, int c, int d) {
    for (int i = 0; i < 4; i++) {
        int next_d = (d + 3 - i) % 4; // 왼쪽 방향으로 회전
        int next_r = r + dx[next_d];
        int next_c = c + dy[next_d];

        if (next_r >= 0 && next_r < MAX_SIZE && next_c >= 0 && next_c < MAX_SIZE && map[next_r][next_c] == 0 && visited[next_r][next_c] == 0) {
            visited[next_r][next_c] = 1;
            clean_count++;
            perform_cleaning(next_r, next_c, next_d);
            return; // 청소 후 복귀
        }
    }

    // 네 방향 모두 청소할 수 없거나 벽인 경우 후진
    int back_d = (d + 2) % 4; // 후진 방향 계산
    int back_r = r + dx[back_d];
    int back_c = c + dy[back_d];

    if (back_r >= 0 && back_r < MAX_SIZE && back_c >= 0 && back_c < MAX_SIZE && map[back_r][back_c] == 0) {
        perform_cleaning(back_r, back_c, d); // 후진
    } else {
        std::cout << clean_count << std::endl; // 더 이상 움직일 수 없으면 청소 카운트 출력
        exit(0);
    }
}

int main() {
    int n, m, r, c, d;
    process_input(n, m, r, c, d);
    perform_cleaning(r, c, d);
    return 0;
}
