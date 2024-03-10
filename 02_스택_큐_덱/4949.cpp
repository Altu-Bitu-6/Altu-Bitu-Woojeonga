#include <iostream>
#include <stack>
#include <string>

using namespace std;

// 괄호의 균형을 검사하는 함수
bool is_balanced(const string& str) {
    stack<char> s;
    for (char ch : str) {
        // 왼쪽 괄호가 나오면 스택에 푸시
        if (ch == '(' || ch == '[') {
            s.push(ch);
        } else if (ch == ')') {
            // 오른쪽 소괄호가 나왔을 때 스택이 비어있거나 짝이 맞지 않으면 false 반환
            if (s.empty() || s.top() != '(') return false;
            s.pop();
        } else if (ch == ']') {
            // 오른쪽 대괄호가 나왔을 때 스택이 비어있거나 짝이 맞지 않으면 false 반환
            if (s.empty() || s.top() != '[') return false;
            s.pop();
        }
    }
    // 모든 검사가 끝난 후 스택이 비어있어야 균형이 잡힘
    return s.empty();
}

int main() {
    string input;
    while (true) {
        getline(cin, input);
        // 입력의 종료 조건 확인
        if (input == ".") break;

        // 균형잡힌 문자열인지 검사하여 결과 출력
        if (is_balanced(input)) {
            cout << "yes" << "\n";
        } else {
            cout << "no" << "\n";
        }
    }
    return 0;
}