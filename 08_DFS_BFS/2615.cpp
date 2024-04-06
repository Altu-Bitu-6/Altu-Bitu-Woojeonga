#include <iostream>
using namespace std;

const int BOARD_SIZE = 19; // 바둑판 크기
int board[BOARD_SIZE][BOARD_SIZE]; // 바둑판 상태 저장

// 연속된 바둑알의 개수를 반환하고, 가장 왼쪽(또는 가장 위) 바둑알의 위치를 참조로 반환하는 함수
int countStones(int x, int y, int dx, int dy, int& start_x, int& start_y) {
    int count = 0;
    int color = board[x][y];
    while (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board[x][y] == color) {
        if (count == 0) { // 연속된 바둑알의 시작 위치 업데이트
            start_x = x;
            start_y = y;
        }
        x += dx;
        y += dy;
        count++;
    }
    return count;
}

// 승부 판정을 위한 함수
void checkWinner() {
    int dx[4] = {1, 0, 1, -1}; // 탐색할 방향 (세로, 가로, 대각선 오른쪽 위, 대각선 오른쪽 아래)
    int dy[4] = {0, 1, 1, 1};
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] != 0) {
                for (int k = 0; k < 4; k++) {
                    int start_x = 0, start_y = 0;
                    if (countStones(i, j, dx[k], dy[k], start_x, start_y) == 5) {
                        // 연속되기 전과 후의 위치를 확인하여 6알 이상 연속되지 않는지 검사
                        if ((!((i-dx[k] >= 0 && i-dx[k] < BOARD_SIZE && j-dy[k] >= 0 && j-dy[k] < BOARD_SIZE) && board[i-dx[k]][j-dy[k]] == board[i][j])) &&
                            (!((start_x+dx[k]*5 >= 0 && start_x+dx[k]*5 < BOARD_SIZE && start_y+dy[k]*5 >= 0 && start_y+dy[k]*5 < BOARD_SIZE) && board[start_x+dx[k]*5][start_y+dy[k]*5] == board[i][j]))) {
                            cout << board[i][j] << "\n"; // 이긴 바둑알 색상 출력
                            cout << start_x + 1 << " " << start_y + 1 << "\n"; // 바둑알 위치 출력
                            return;
                        }
                    }
                }
            }
        }
    }
    cout << 0 << endl; // 승부가 결정되지 않음
}

int main() {
    // 바둑판 상태 입력
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            cin >> board[i][j];
        }
    }
    
    checkWinner(); // 승부 판정

    return 0;
}
