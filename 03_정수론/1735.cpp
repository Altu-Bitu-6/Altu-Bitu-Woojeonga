#include <iostream>
using namespace std;

// 최대공약수를 찾는 함수
int gcd(int a, int b) {
    if (b == 0) { // b가 0이면, a는 b와 나누어 떨어지는 것 -> a가 최대공약수
        return a;
    } else {
        return gcd(b, a % b);
    }
}

// 두 분수의 합을 계산하고 기약분수 형태로 만드는 함수
void calc_simp(int n1, int d1, int n2, int d2, int &rn, int &rd) {
    rn = n1 * d2 + n2 * d1; // 합분수 분자
    rd = d1 * d2; // 합분수 분모
    int g = gcd(rn, rd); // 최대공약수
    rn /= g; // 기약분수 분자
    rd /= g; // 기약분수 분모
}

int main() {
    int n1, d1; // 첫 번째 분수의 분자와 분모
    int n2, d2; // 두 번째 분수의 분자와 분모
    int result_numerator, result_denominator; // 결과 분수의 분자와 분모

    // 입력 받기
    cin >> n1 >> d1;
    cin >> n2 >> d2;

    // 분수의 합과 기약분수 계산
    calc_simp(n1, d1, n2, d2, result_numerator, result_denominator);

    // 결과 출력
    cout << result_numerator << " " << result_denominator << "\n";
    return 0;
}
