#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T; // 테스트 케이스 개수
    cin >> T;

    while (T--) {
        int N; // 지원자 수
        cin >> N;

        vector<pair<int, int>> applicants(N); // 각 지원자의 서류 심사 성적과 면접 성적 순위를 저장하는 벡터
        
        for (int i = 0; i < N; ++i) {
            cin >> applicants[i].first >> applicants[i].second;
        }

        // 서류 심사 성적으로 정렬(서류 심사의 순위가 높은 순)
        sort(applicants.begin(), applicants.end());

        int result = 1; // 첫 번째 지원자는 항상 선발
        int interviewRank = applicants[0].second; // 첫 번째 지원자의 면접 성적 순위

        for (int i = 1; i < N; ++i) {
            if (applicants[i].second < interviewRank) { // 면접 순위가 더 높은 경우(숫자는 더 작음)
                result++; // 선발 인원 증가
                interviewRank = applicants[i].second; // 기준점(최고 면접 성적 순위) 갱신
            }
        }

        cout << result << '\n';
    }

    return 0;
}
