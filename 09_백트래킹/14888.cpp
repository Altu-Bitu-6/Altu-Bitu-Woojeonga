#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// 상수
const int MAX_INT = 1000000000; // 10억
const int MIN_INT = -1000000000; // -10억

// 연산을 수행하는 함수
int calculate(int current_value, int next_number, char operator_type) {
    switch (operator_type) {
        case '+':
            return current_value + next_number;
        case '-':
            return current_value - next_number;
        case '*':
            return current_value * next_number;
        case '/':
            if (current_value < 0) {
                return -(-current_value / next_number);
            } else {
                return current_value / next_number;
            }
        default:
            return 0; // 이 경우는 발생하지 않음
    }
}

// 가능한 모든 연산자 조합을 생성하고 결과를 계산하는 함수
void explore_operations(vector<int>& numbers, vector<char>& operators, int index, int current_value, int& max_result, int& min_result) {
    if (index == numbers.size()) {
        max_result = max(max_result, current_value);
        min_result = min(min_result, current_value);
        return;
    }

    for (int i = 0; i < operators.size(); ++i) {
        if (operators[i] != ' ') {
            char op = operators[i];
            operators[i] = ' '; // 연산자를 사용했다고 표시
            int next_value = calculate(current_value, numbers[index], op);
            explore_operations(numbers, operators, index + 1, next_value, max_result, min_result);
            operators[i] = op; // 연산자 사용 취소
        }
    }
}

// 메인 연산 로직을 처리하는 함수
void calculate_expressions(vector<int>& numbers, vector<int>& op_count) {
    vector<char> operators;
    for (int i = 0; i < 4; ++i) {
        char op;
        switch (i) {
            case 0: op = '+'; break;
            case 1: op = '-'; break;
            case 2: op = '*'; break;
            case 3: op = '/'; break;
        }
        for (int j = 0; j < op_count[i]; ++j) {
            operators.push_back(op);
        }
    }

    int max_result = MIN_INT;
    int min_result = MAX_INT;
    explore_operations(numbers, operators, 1, numbers[0], max_result, min_result);

    cout << max_result << "\n" << min_result << endl;
}

int main() {
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    vector<int> op_count(4);
    cin >> op_count[0] >> op_count[1] >> op_count[2] >> op_count[3];

    calculate_expressions(numbers, op_count);

    return 0;
}
