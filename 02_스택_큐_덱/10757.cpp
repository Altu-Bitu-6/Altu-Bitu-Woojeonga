#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;

// 정수 타입으로 연산 불가
// 문자열로 표현된 두 수를 더하는 함수
string add_large_numbers(const string& a, const string& b) {
    string result = ""; // 결과를 저장할 문자열
    int carry = 0; // 자리올림 수
    int sum = 0; // 각 자리의 합

    // 두 수의 길이를 맞추기 위해 더 짧은 수의 앞을 0으로 채움
    string a_padded = a;
    string b_padded = b;
    while (a_padded.length() < b_padded.length()) a_padded = "0" + a_padded;
    while (b_padded.length() < a_padded.length()) b_padded = "0" + b_padded;

    // 두 수의 각 자리를 거꾸로 더해감 (가장 낮은 자리부터 시작)
    for (int i = a_padded.length() - 1; i >= 0; i--) {
        sum = (a_padded[i] - '0') + (b_padded[i] - '0') + carry; // 각 자리수와 자리올림 수를 더함
        carry = sum / 10; // 다음 자리로 올릴 값 계산
        result += (sum % 10) + '0'; // 결과 문자열에 현재 자리의 합 추가
    }

    // 마지막 자리올림이 있을 경우 결과에 추가
    if (carry > 0) {
        result += carry + '0';
    }

    // 결과 문자열을 뒤집어서 정상 순서로 만듦
    reverse(result.begin(), result.end());

    return result;
}

int main() {
    string a, b;
    cin >> a >> b; // 두 큰 수 입력 받음

    // 입력받은 두 수를 더하고 결과 출력
    cout << add_large_numbers(a, b) << "\n";

    return 0;
}
