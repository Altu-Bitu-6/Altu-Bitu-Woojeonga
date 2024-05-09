#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 전역 변수 선언
int total_gears, rotation_count; // 톱니바퀴의 총 수와 회전 수를 저장
vector<vector<int>> gear_states; // 각 톱니바퀴의 상태를 저장(1-indexed)
vector<pair<int, int>> rotation_commands; // 회전 명령을 저장(톱니바퀴 번호, 회전 방향)

// 방향 반전 함수
int reverse_direction(int dir) {
    return (dir == 1) ? -1 : 1; // 시계 방향이면 반시계 방향을, 반시계 방향이면 시계 방향을 반환
}

// 입력 처리 함수
void input_gear_states() {
    cin >> total_gears; // 톱니바퀴의 총 수를 입력 받음
    gear_states.resize(total_gears + 1); // 1-indexed로 사용하기 때문에 +1 
    for (int i = 1; i <= total_gears; ++i) {
        string state; // 톱니바퀴의 상태를 나타내는 문자열을 입력받기
        cin >> state;
        for (char s : state) {// 문자열의 각 문자(극성)를 숫자로 변환하여 저장
            gear_states[i].push_back(s - '0');
        }
    }
    cin >> rotation_count; // 회전 수를 입력 받음
    for (int i = 0; i < rotation_count; ++i) {
        int gear_index, direction; // 회전시킬 톱니바퀴의 번호와 방향을 입력받기
        cin >> gear_index >> direction;
        rotation_commands.emplace_back(gear_index, direction); // 명령을 벡터에 저장
    }
}

// 회전할 톱니바퀴를 찾는 함수
vector<pair<int, int>> find_turning_gears(int idx, int dir) {
    vector<pair<int, int>> turning_gears; // 회전할 톱니바퀴와 방향의 쌍을 저장
    turning_gears.emplace_back(idx, dir); // 초기 톱니바퀴를 추가
    int current_side = gear_states[idx][2]; // 현재 톱니바퀴의 오른쪽 톱니
    int current_dir = dir;

    // 오른쪽 톱니바퀴들 확인
    for (int i = idx + 1; i <= total_gears; ++i) {
        int opposite_side = gear_states[i][6]; // 인접한 톱니바퀴의 왼쪽 톱니
        if (current_side != opposite_side) { // 극성이 다르면 반대 방향으로 회전
            current_dir = reverse_direction(current_dir);
            turning_gears.emplace_back(i, current_dir); // 회전할 톱니바퀴를 추가
            current_side = gear_states[i][2];
        } else {
            break; // 극성이 같으면 더 이상 검사하지 않고 종료
        }
    }

    // 왼쪽 톱니바퀴들 확인
    current_side = gear_states[idx][6]; // 현재 톱니바퀴의 왼쪽 톱니
    current_dir = dir;
    for (int i = idx - 1; i >= 1; --i) {
        int opposite_side = gear_states[i][2]; // 인접한 톱니바퀴의 오른쪽 톱니
        if (current_side != opposite_side) {// 극성이 다르면 반대 방향으로 회전
            current_dir = reverse_direction(current_dir);
            turning_gears.emplace_back(i, current_dir);
            current_side = gear_states[i][6];
        } else {
            break;
        }
    }

    return turning_gears;
}

// 톱니바퀴 회전 함수
void turn_gear(int idx, int dir) { // idx는 회전시킬 톱니바퀴의 인덱스, dir은 회전 방향(1: 시계, -1: 반시계)
    if (dir == 1) {// 시계 방향 회전시, 톱니바퀴의 마지막 요소를 제거하고, 맨 앞에 삽입
        int temp = gear_states[idx].back();
        gear_states[idx].pop_back();
        gear_states[idx].insert(gear_states[idx].begin(), temp);
    } else {// 반시계 방향 회전시, 톱니바퀴의 첫 번째 요소를 제거하고, 맨 뒤에 삽입
        int temp = gear_states[idx].front();
        gear_states[idx].erase(gear_states[idx].begin());
        gear_states[idx].push_back(temp);
    }
}

// 톱니바퀴 회전 실행 함수
void perform_turning(const vector<pair<int, int>>& turning_gears) {
    // turning_gears: 회전할 톱니바퀴들의 인덱스와 해당 방향을 담은 벡터
    for (const auto& gear : turning_gears) {
        // 각 톱니바퀴에 대해 회전 함수를 호출
        turn_gear(gear.first, gear.second);
    }
}

// 해결 함수
void solve() {
    input_gear_states();
    for (const auto& cmd : rotation_commands) {
        auto turning_gears = find_turning_gears(cmd.first, cmd.second);// 회전할 톱니바퀴를 찾기
        perform_turning(turning_gears);// 찾은 톱니바퀴를 회전
    }

    int count_south_poles = 0;
    for (int i = 1; i <= total_gears; ++i) {
        if (gear_states[i][0] == 1) {
            ++count_south_poles;
        }
    }
    cout << count_south_poles << endl;
}

// 메인 함수
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}