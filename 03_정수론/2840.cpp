#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 바퀴의 상태를 업데이트하는 함수
void updateWheel(vector<char>& wheel, int shift, char letter, int& start_pos, int N) {
    // shift: 회전수, letter: 회전 후 화살표가 가리키는 글자, start_pos: 현재 화살표 위치, N: 바퀴의 칸 수
    // 화살표가 가리키는 위치를 업데이트
    start_pos = (start_pos + shift) % N;

    // 해당 위치에 글자를 업데이트
    wheel[start_pos] = letter;
}

// 바퀴에 적힌 알파벳을 출력하는 함수
string printWheel(const vector<char>& wheel, int start_pos, int N) {
    string result = "";
    // 시작 위치부터 시계 방향으로 바퀴에 적힌 알파벳을 추가
    for (int i = 0; i < N; ++i) {
        int pos = (start_pos + i) % N; // 바퀴가 N 칸을 넘어서 회전할 경우 다시 0부터 시작
        result += wheel[pos] == '\0' ? '?' : wheel[pos]; // wheel의 pos 위치에 있는 문자가 널 문자(\0)인지 비교
    }
    return result;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<char> wheel(N, '\0'); // 바퀴의 각 칸에 대한 정보를 저장하는 배열
    int start_pos = 0; // 화살표가 처음 가리키는 위치

    for (int i = 0; i < K; ++i) {
        int shift;
        char letter;
        cin >> shift >> letter;
        
        // 바퀴 업데이트
        updateWheel(wheel, shift, letter, start_pos, N);
    }

    // 결과 출력
    cout << printWheel(wheel, start_pos, N) << "\n";

    return 0;
}
