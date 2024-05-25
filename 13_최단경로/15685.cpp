#include <iostream>
#include <vector>
using namespace std;

const int MAX_GRID_SIZE = 101; // 격자의 최대 크기
const int DIRECTIONS = 4; // 방향의 개수

// 방향 배열 (→, ↑, ←, ↓)
const int DX[DIRECTIONS] = {1, 0, -1, 0};
const int DY[DIRECTIONS] = {0, -1, 0, 1};

// 드래곤 커브 정보를 저장할 구조체
struct DragonCurve {
    int x, y, direction, generation;
};

// 격자 배열
bool grid[MAX_GRID_SIZE][MAX_GRID_SIZE] = {false};

// 드래곤 커브를 그리는 함수
void draw_dragon_curve(int x, int y, int direction, int generation) {
    vector<int> directions; // 방향을 저장하는 벡터
    directions.push_back(direction); // 시작 방향 추가

    // 각 세대별로 방향을 추가
    for (int g = 0; g < generation; g++) {
        int size = directions.size();
        for (int i = size - 1; i >= 0; i--) {
            directions.push_back((directions[i] + 1) % 4); // 90도 회전
        }
    }

    // 드래곤 커브 그리기
    grid[y][x] = true; // 시작 점
    for (int dir : directions) {
        x += DX[dir];
        y += DY[dir];
        grid[y][x] = true; // 드래곤 커브의 각 점을 그리기
    }
}

// 1x1 정사각형의 개수를 세는 함수
int count_squares() {
    int count = 0;
    // 1x1 정사각형을 찾기 위해 격자를 탐색
    for (int i = 0; i < MAX_GRID_SIZE - 1; i++) {
        for (int j = 0; j < MAX_GRID_SIZE - 1; j++) {
            // 정사각형의 네 꼭짓점이 모두 드래곤 커브의 일부인지 확인
            if (grid[i][j] && grid[i+1][j] && grid[i][j+1] && grid[i+1][j+1]) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n; // 드래곤 커브의 개수 입력

    vector<DragonCurve> curves(n); // 드래곤 커브 정보 저장 벡터

    // 드래곤 커브 정보 입력
    for (int i = 0; i < n; i++) {
        cin >> curves[i].x >> curves[i].y >> curves[i].direction >> curves[i].generation;
    }

    // 각 드래곤 커브를 그리기
    for (const auto& curve : curves) {
        draw_dragon_curve(curve.x, curve.y, curve.direction, curve.generation);
    }

    // 정사각형의 개수를 세어 출력
    cout << count_squares() << endl;

    return 0;
}
