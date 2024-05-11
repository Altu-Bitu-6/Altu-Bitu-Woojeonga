#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 최장 연속 부분 수열의 길이를 계산하는 함수
int findLongestSubsequence(const vector<int>& sequence, int k) {
    unordered_map<int, int> freq; // 원소의 빈도수를 저장할 해시맵
    int start = 0; // 부분 수열의 시작 인덱스
    int max_length = 0; // 최대 부분 수열 길이

    for (int end = 0; end < sequence.size(); ++end) {
        freq[sequence[end]]++; // 현재 원소의 빈도수 증가

        // 현재 원소의 빈도수가 k를 초과하는 동안 시작 인덱스를 이동
        while (freq[sequence[end]] > k) {
            freq[sequence[start]]--; // 시작 원소의 빈도수 감소
            start++; // 시작 인덱스 증가
        }

        // 최대 길이 갱신
        max_length = max(max_length, end - start + 1);
    }

    return max_length;
}

int main() {
    int n, k;
    cin >> n >> k; // 수열의 길이와 최대 허용 빈도수 입력 받기
    vector<int> sequence(n); // 수열 저장할 벡터

    for (int i = 0; i < n; ++i) {
        cin >> sequence[i]; // 수열 원소 입력 받기
    }

    // 최장 연속 부분 수열의 길이를 계산하고 출력
    cout << findLongestSubsequence(sequence, k) << endl;

    return 0;
}
