#include <iostream>
#include <string>
using namespace std;

void add(int& S, int x) {
    S |= (1 << (x - 1)); // 1을 x-1번 왼쪽으로 시프트
}

void remove(int& S, int x) {
    S &= ~(1 << (x - 1)); // x번째 비트만 0이고 나머지는 모두 1인 마스크를 생성 -> AND 연산
}

int check(int S, int x) { // S에 x번째 원소가 존재하는지 확인. 결과가 0이 아니면 원소가 존재하는 것이므로 1을, 그렇지 않으면 0을 반환
    return (S & (1 << (x - 1))) ? 1 : 0;
}

void toggle(int& S, int x) {
    S ^= (1 << (x - 1));
}

void all(int& S) {
    S = (1 << 20) - 1;
}

void empty(int& S) {
    S = 0;
}

int main() {
    ios_base::sync_with_stdio(false); // 입출력 속도 향상 목적
    cin.tie(NULL); // 입출력 속도 향상 목적
    int M, S = 0; // 연산의 수 M과 집합 S 초기화
    cin >> M; // 연산의 수 입력 받기

    for (int i = 0; i < M; i++) {
        string cmd;
        int x;
        cin >> cmd; // 연산 명령어 입력 받기
        
        if (cmd == "add") {
            cin >> x;
            add(S, x);
        } else if (cmd == "remove") {
            cin >> x;
            remove(S, x);
        } else if (cmd == "check") {
            cin >> x;
            cout << check(S, x) << '\n'; // 결과 출력
        } else if (cmd == "toggle") {
            cin >> x;
            toggle(S, x);
        } else if (cmd == "all") {
            all(S);
        } else if (cmd == "empty") {
            empty(S);
        }
    }
    
    return 0;
}
