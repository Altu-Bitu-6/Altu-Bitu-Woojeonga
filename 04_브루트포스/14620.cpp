#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const int MAX_N = 10;
int garden[MAX_N][MAX_N]; // 화단의 가격 정보
int N; // 화단의 크기

// 꽃잎이 화단 밖으로 나가는지 검사하는 함수
bool is_out_of_bounds(int x, int y) {
    return x < 0 || x >= N || y < 0 || y >= N;
}

// 꽃을 심었을 때의 비용을 계산하는 함수
int calculate_cost(vector<pair<int, int>>& flowers) {
    int cost = 0;
    bool visited[MAX_N][MAX_N] = {false}; // 꽃잎이 겹치는지 확인하기 위함
    
    // 상, 하, 좌, 우, 중앙의 위치 변화량
    int dx[5] = {0, 0, -1, 1, 0}; // 꽃을 심는 위치의 중심을 기준으로 상, 하, 좌, 우, 그리고 중심 자체의 x 좌표 변화량을 나타내는 배열
    int dy[5] = {-1, 1, 0, 0, 0};
    
    for (auto &flower : flowers) { // 주어진 모든 꽃의 위치(flowers)에 대해 반복
        for (int i = 0; i < 5; ++i) {
            int nx = flower.first + dx[i]; // 현재 꽃잎의 x 좌표를 계산
            int ny = flower.second + dy[i];
            
            // 화단 밖으로 나가거나 이미 다른 꽃에 의해 사용된 경우
            if (is_out_of_bounds(nx, ny) || visited[nx][ny]) {
                return INT_MAX; // 최대 비용 반환
            }
            
            visited[nx][ny] = true; // 꽃잎이 차지하는 위치 표시
            cost += garden[nx][ny]; // 해당 위치의 가격을 비용에 추가
        }
    }
    return cost;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> garden[i][j];
        }
    }
    
    int min_cost = INT_MAX;
    // 꽃을 심을 수 있는 모든 조합을 찾아 최소 비용 계산
    for (int i = 0; i < N * N; ++i) {
        for (int j = i + 1; j < N * N; ++j) {
            for (int k = j + 1; k < N * N; ++k) {
                vector<pair<int, int>> flowers = {{i / N, i % N}, {j / N, j % N}, {k / N, k % N}};
                int cost = calculate_cost(flowers);
                min_cost = min(min_cost, cost);
            }
        }
    }
    
    cout << min_cost << '\n'; // 최소 비용 출력
    
    return 0;
}
