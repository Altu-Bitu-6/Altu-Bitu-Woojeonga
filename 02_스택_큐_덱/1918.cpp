#include <iostream>
#include <stack>
#include <string>

using namespace std;

// 연산자의 우선순위를 반환하는 함수(곱셈, 나눗셈의 우선순위가 덧셈, 뺄셈 우선 순위보다 높음)
int get_precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// 중위 표기식을 후위 표기식으로 변환하는 함수
string infix_to_postfix(const string& infix) {
    string postfix;
    stack<char> op_stack;

    for (char token : infix) {
        // token: 중위 표기식의 현재 문자
        // 피연산자인 경우 바로 postfix에 추가
        if (isalpha(token)) {
            postfix += token;
        }
        // '('는 스택에 푸시: 연산자의 우선순위를 높이는 역할
        else if (token == '(') {
            op_stack.push(token);
        }
        // ')'는 '('를 만날 때까지 스택을 팝하면서 postfix에 추가
        else if (token == ')') {
            while (!op_stack.empty() && op_stack.top() != '(') {
                postfix += op_stack.top();
                op_stack.pop();
            }
            op_stack.pop(); // '(' 제거
        }
        // 연산자인 경우
        else {
            // 스택의 top에 있는 연산자 우선순위가 현재 연산자보다 크거나 같으면 팝해서 postfix에 추가
            while (!op_stack.empty() && get_precedence(op_stack.top()) >= get_precedence(token)) {
                postfix += op_stack.top();
                op_stack.pop();
            }
            // 현재 연산자는 스택에 푸시
            op_stack.push(token);
        }
    }

    // 스택에 남아있는 연산자들을 모두 팝해서 postfix에 추가
    while (!op_stack.empty()) {
        postfix += op_stack.top();
        op_stack.pop();
    }

    return postfix;
}

int main() {
    string infix;
    getline(cin, infix); // 중위 표기식 입력 받음

    // 중위 표기식을 후위 표기식으로 변환하여 출력
    cout << infix_to_postfix(infix) << "\n";

    return 0;
}