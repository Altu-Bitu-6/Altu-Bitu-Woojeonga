#include <iostream>
#include <vector>
using namespace std;

// 가장 긴 증가하는 부분 수열의 길이를 계산하는 함수
int find_lis_length(const vector<int>& sequence) {
    int n = sequence.size();
    vector<int> dp(n, 1); // 모든 위치에 대해 LIS의 최소 길이는 1로 초기화

    // 각 위치에 대한 LIS 길이 계산
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (sequence[i] > sequence[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // dp 배열에서 최대 길이 찾기
    int max_length = 0;
    for (int i = 0; i < n; i++) {
        max_length = max(max_length, dp[i]);
    }

    return max_length; // 가장 긴 증가하는 부분 수열의 길이 반환
}

int main() {
    int n; // 수열 A의 크기
    cin >> n; // 수열의 크기 입력 받기
    vector<int> sequence(n); // 수열 A를 저장할 벡터

    // 수열 A의 원소 입력 받기
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    // 가장 긴 증가하는 부분 수열의 길이 계산 및 출력
    cout << find_lis_length(sequence) << '\n';

    return 0; // 프로그램 종료
}
