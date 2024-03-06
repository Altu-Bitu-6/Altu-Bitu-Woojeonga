#include <iostream>
#include <vector>

using namespace std;

// int_char_pair: 회전 횟수와 해당 시점에 화살표가 가리키는 글자를 저장하는 pair
typedef pair<int, char> int_char_pair;

// MAX_ALPHA: 사용 가능한 알파벳의 최대 개수를 나타내는 상수
const int MAX_ALPHA = 26;

// print_wheel: 주어진 바퀴의 상태를 바탕으로 알파벳을 시계방향으로 출력하는 함수
string print_wheel(int n, int index, vector<char>& wheel) {
    string ans = ""; // 결과 문자열을 저장할 변수
    // 바퀴를 반시계방향으로 돌리면서 문자열 생성
    for (int i = index + n; i > index; --i) {
        ans += wheel[i % n];
    }
    return ans; // 최종 결과 문자열 반환
}

// make_wheel: 주어진 입력을 바탕으로 행운의 바퀴를 만들고, 그 결과를 문자열로 반환하는 함수
string make_wheel(int n, int k, vector<int_char_pair>& record) {
    vector<char> wheel(n, '?'); // 바퀴의 각 칸을 '?'로 초기화
    vector<bool> is_available(MAX_ALPHA, false); // 각 알파벳의 사용 여부를 추적

    int index = 0; // 현재 화살표가 가리키는 인덱스

    // 모든 회전 정보를 처리
    for (int i = 0; i < k; ++i) {
        int s = record[i].first; // 화살표가 가리키는 글자가 변하는 횟수
        char ch = record[i].second; // 회전을 멈추었을 때 가리키던 글자

        index = (index + s) % n; // 회전 후 화살표의 새로운 위치 계산

        // 해당 위치에 이미 같은 글자가 있는 경우, 다음 기록으로 넘어감
        if (wheel[index] == ch) {
            continue;
        }

        // 해당 위치에 다른 글자가 있거나, 알파벳이 이미 사용되었으면 모순
        if (wheel[index] != '?' || is_available[ch - 'A']) {
            return "!"; // 모순을 나타내는 "!" 반환
        }

        wheel[index] = ch; // 바퀴에 글자 할당
        is_available[ch - 'A'] = true; // 해당 알파벳을 사용했음을 표시
    }
    return print_wheel(n, index, wheel); // 최종 바퀴 상태 출력
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k; // 바퀴의 칸 수, 회전 횟수
    cin >> n >> k;

    vector<int_char_pair> record(k); // 회전 정보를 저장하는 벡터
    for (int i = 0; i < k; ++i) {
        cin >> record[i].first >> record[i].second; // 회전 횟수와 글자 입력 받기
    }

    // 행운의 바퀴 생성 및 결과 출력
    cout << make_wheel(n, k, record);

    return 0;
}