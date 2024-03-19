#include <iostream>
using namespace std;

// 필요한 물병의 최소 개수를 계산하는 함수
int calculate_minimum_bottles(int n, int k) {
    int additional_bottles = 0; // 필요한 추가 물병의 개수

    while (true) {
        int bottle_count = 0; // 현재 물병의 개수
        int temp_n = n + additional_bottles; // 현재 물병과 추가된 물병의 총합

        // 비트 연산을 이용하여 물병 재분배 가능 여부 판단
        // 각 비트가 물병 하나를 나타내고, 그 물병이 가득 차 있으면 1, 아니면 0을 의미
        while (temp_n > 0) {
            if (temp_n % 2 == 1) { // 현재 물병이 홀수 개인 경우
                bottle_count++;
            }
            temp_n /= 2;
        }

        if (bottle_count <= k) { // 재분배 후 물병 개수가 K개 이하인 경우
            break;
        }

        additional_bottles++; // 추가 물병 필요
    }

    return additional_bottles;
}

int main() {
    int n; // 현재 물병의 개수
    int k; // 한 번에 옮길 수 있는 최대 물병의 개수

    // 사용자로부터 입력 받기
    cin >> n >> k;

    // 필요한 추가 물병의 최소 개수를 계산
    int result = calculate_minimum_bottles(n, k);

    // 결과 출력
    cout << result << "\n";

    return 0;
}
