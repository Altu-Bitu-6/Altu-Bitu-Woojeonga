#include <iostream>
#include <string>
using namespace std;

// 종말의 수를 찾는 함수
int find_series_of_end_number(int n) {
    int count = 0; // 찾은 종말의 수의 개수
    for (int i = 666; ; i++) { //  666: 가장 첫 번째 종말의 수
        string number = to_string(i);
        // 현재 숫자에 '666'이 포함되어 있는지 확인
        if (number.find("666") != string::npos) { //string::npos - 문자열에서 검색된 부분문자열이 없음을 나타내는 특수한 값
            count++;
            // N번째 종말의 수를 찾은 경우
            if (count == n) {
                return i; // 해당 숫자를 반환
            }
        }
    }
}

int main() {
    int n; // 사용자로부터 입력받은 N값
    cin >> n; // N 입력 받기
    
    int result = find_series_of_end_number(n); // 종말의 수 찾기
    cout << result << "\n"; // 결과 출력
    
    return 0;
}
