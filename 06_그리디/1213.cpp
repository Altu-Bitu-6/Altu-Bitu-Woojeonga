#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int ALPHABET_COUNT = 26; 

// 팰린드롬 생성 함수
string create_palindrome(const string& name) {
    vector<int> char_count(ALPHABET_COUNT, 0); // 알파벳 개수를 세기 위한 벡터
    for (char ch : name) {
        char_count[ch - 'A']++; // 각 문자의 빈도수 계산
    }

    int odd_count = 0; // 홀수 개수 문자 체크
    for (int count : char_count) {
        if (count % 2 == 1) {
            odd_count++;
        }
    }

    if (odd_count > 1) { // 홀수 개수 문자가 1개 이상이면 팰린드롬 불가능
        return "I'm Sorry Hansoo";
    }

    string first_half = ""; // 팰린드롬 첫 번째 절반
    string middle_char = ""; // 홀수 개수 문자
    // 홀수 개수의 문자가 있는 경우, 해당 문자는 팰린드롬의 정중앙에 위치해야 함
    for (int i = 0; i < ALPHABET_COUNT; i++) {
        if (char_count[i] % 2 == 1) {
            middle_char += (char)('A' + i);
            char_count[i]--;
        }
        first_half += string(char_count[i] / 2, 'A' + i); // 팰린드롬 첫 번째 절반 구성
    }

    string palindrome = first_half + middle_char + string(first_half.rbegin(), first_half.rend()); // 전체 팰린드롬 구성
    return palindrome;
}

int main() {
    string hansoo_name; // 임한수의 영어 이름
    cin >> hansoo_name; // 이름 입력

    string palindrome = create_palindrome(hansoo_name); // 팰린드롬 생성
    cout << palindrome; // 결과 출력

    return 0;
}
