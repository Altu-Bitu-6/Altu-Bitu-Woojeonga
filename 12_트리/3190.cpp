#include <iostream>
#include <vector>
#include <deque>
#include <map>

using namespace std;
typedef pair<int, int> ci; // 좌표를 표현하기 위한 pair 타입 정의

const int EMPTY = 0; // 빈 칸
const int APPLE = 1; // 사과가 있는 칸
const int SNAKE = 2; // 뱀이 있는 칸

/**
 * 게임이 몇 초에 끝나는지 계산
 * @param n 보드의 크기
 * @param board 게임 보드 (사과, 뱀의 위치가 표시됨)
 * @param cmd 시간별 방향 변환 명령어
 * @return 게임이 종료되는 시간 (초)
 */
int playGame(int n, vector<vector<int>> &board, map<int, char> &cmd) {
    // 동(→), 남(↓), 서(←), 북(↑) 방향 배열
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    // 초기화
    deque<ci> snake; // 뱀의 위치 정보 저장하는 deque
    snake.push_front({1, 1}); // 뱀의 초기 위치 (1, 1)
    board[1][1] = SNAKE; // 보드에서 뱀의 위치를 표시

    int time = 0; // 현재 시간
    int dir = 0;  // 현재 방향 (동쪽 시작)
    while (true) {
        // 방향 변환 정보가 있다면
        if (cmd.find(time) != cmd.end()) { // 현재 시간이 방향 변환 명령어가 있는 시간인지 확인
            if (cmd[time] == 'L') { // 왼쪽 회전
                dir = (dir + 3) % 4; // 왼쪽 회전 (반시계 방향)
            } else if (cmd[time] == 'D') { // 오른쪽 회전
                dir = (dir + 1) % 4; // 오른쪽 회전 (시계 방향)
            }
        }

        // 시간 증가
        time++;

        // 다음에 뱀의 머리가 위치하게 될 칸 계산
        int nx = snake.front().first + dx[dir];
        int ny = snake.front().second + dy[dir];

        // 게임 종료 조건: 벽에 부딪히거나, 자기 자신의 몸에 부딪힘
        if (nx < 1 || nx > n || ny < 1 || ny > n || board[nx][ny] == SNAKE) {
            break; // 게임 종료
        }

        // 이동
        snake.push_front({nx, ny}); // 뱀의 머리를 다음 칸에 위치시킴
        if (board[nx][ny] != APPLE) { // 이동한 칸에 사과가 없다면
            ci tail = snake.back(); // 꼬리 위치 저장
            board[tail.first][tail.second] = EMPTY; // 보드에서 꼬리 위치 비우기
            snake.pop_back(); // 꼬리 제거
        }
        board[nx][ny] = SNAKE; // 보드에서 새로운 머리 위치를 뱀으로 표시
    }
    return time; // 게임이 종료된 시간 반환
}

int main() {
    int n, k, x, y, l, time;
    char command;

    // 입력
    cin >> n >> k; // 보드 크기와 사과의 개수 입력
    vector<vector<int>> board(n + 1, vector<int>(n + 1, EMPTY)); // 보드 초기화
    while (k--) {
        cin >> x >> y; // 사과의 위치 입력
        board[x][y] = APPLE; // 보드에 사과 위치 표시
    }
    cin >> l; // 방향 변환 횟수 입력
    map<int, char> cmd; // 방향 변환 명령 저장할 map
    while (l--) {
        cin >> time >> command; // 시간과 명령어 입력
        cmd[time] = command; // 명령어 저장
    }

    // 연산 및 출력
    cout << playGame(n, board, cmd); // 게임 실행 및 결과 출력
    return 0;
}
