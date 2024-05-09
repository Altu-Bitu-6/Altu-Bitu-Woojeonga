#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 입력 변수 선언(굴다리 길이, 가로등 수, 가로등 위치를 저장)
int bridge_length;
int lamp_count;
vector<int> lamp_positions;

// 입력을 처리하는 함수: 굴다리 길이와 가로등 수를 입력받고, 가로등 위치를 벡터에 저장
void input() {
    cin >> bridge_length >> lamp_count;  // 굴다리 길이와 가로등 수를 입력
    lamp_positions.resize(lamp_count); // 가로등 위치를 저장할 벡터의 크기를 설정
    for (int i = 0; i < lamp_count; i++) {
        cin >> lamp_positions[i]; // 가로등 위치 입력
    }
    sort(lamp_positions.begin(), lamp_positions.end());  // 가로등 위치를 오름차순으로 정렬
}

// 모든 지점을 비출 수 있는지 검사
bool can_shine_all(int height) {
    int last_covered = 0; // 마지막으로 비춰진 위치 추적
    for (int i = 0; i < lamp_count; i++) {
        if (lamp_positions[i] - height > last_covered) {
            // 현재 가로등의 빛이 이전에 비춰진 마지막 위치를 커버하지 못하는 경우
            return false;
        }
        last_covered = lamp_positions[i] + height; // 마지막으로 비춰진 위치 갱신
        if (last_covered >= bridge_length) {
            // 모든 지점이 비춰졌다면 true 반환
            return true;
        }
    }
    // 반복문이 끝났을 때 마지막으로 비춰진 위치가 굴다리 길이를 커버하는지 검사
    return last_covered >= bridge_length;
}

// 최소 높이를 찾는 이진 탐색 함수
int find_minimum_height() {
    int start = 0; // 최소 높이 범위 시작
    int end = bridge_length; // 최소 높이 범위 끝
    int result = 0; // 최소 높이 결과를 저장할 변수

    while (start <= end) {
        int mid = (start + end) / 2; // 중간값 계산
        if (can_shine_all(mid)) {
            // 중간값으로 모든 지점을 비출 수 있으면
            result = mid; // 결과를 갱신하고
            end = mid - 1; // 더 작은 높이를 탐색
        } else {
            // 중간값으로 모든 지점을 비출 수 없으면
            start = mid + 1; // 더 큰 높이를 탐색
        }
    }
    return result; // 계산된 최소 높이 반환
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    cout << find_minimum_height() << endl;

    return 0;
}
