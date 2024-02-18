#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
    int N, M, count = 0;
    cin >> N >> M; // N과 M 입력 받기

    unordered_set<string> S; // 집합 S를 저장할 해시 테이블
    string str;

    // 집합 S에 포함될 문자열 입력 받기
    for(int i = 0; i < N; i++) {
        cin >> str;
        S.insert(str); // 입력 받은 문자열을 집합 S에 삽입
    }

    // 검사할 문자열 입력 받고, 집합 S에 포함되어 있는지 확인
    for(int i = 0; i < M; i++) {
        cin >> str;
        if(S.count(str)) { // 집합 S에 문자열이 포함되어 있는지 검사
            count++; // 포함되어 있다면 카운트 증가
        }
    }

    cout << count << endl; // 결과 출력

    return 0;
}