#include <iostream>
#include <vector>
using namespace std;

// 계단의 점수를 기반으로 최대 점수를 계산하는 함수
int calculate_max_score(const vector<int>& stairs) {
    int n = stairs.size();
    if (n == 0) return 0; // 계단이 없는 경우
    vector<int> dp(n+1, 0); // dp 배열 초기화

    // 초기 조건 설정
    dp[1] = stairs[0];
    if (n > 1) dp[2] = stairs[0] + stairs[1];

    // 점화식을 이용한 dp 배열 채우기
    for (int i = 3; i <= n; i++) {
        dp[i] = max(dp[i-2], dp[i-3] + stairs[i-2]) + stairs[i-1];
    }

    return dp[n]; // 최대 점수 반환
}

int main() {
    int n; // 계단의 개수
    cin >> n; // 사용자로부터 계단의 개수 입력 받기
    vector<int> stairs(n); // 계단 점수를 저장할 벡터

    // 계단 점수 입력 받기
    for (int i = 0; i < n; i++) {
        cin >> stairs[i];
    }

    // 최대 점수 계산 및 출력
    cout << calculate_max_score(stairs) << '\n';

    return 0; // 프로그램 종료
}
