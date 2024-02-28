#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 오큰수를 찾는 함수
vector<int> find_next_greater_elements(const vector<int>& sequence) {
    int n = sequence.size();
    vector<int> nge(n, -1); // 결과 배열을 -1로 초기화: -1은 오큰수가 없음을 의미
    stack<int> s; // 인덱스를 저장할 스택

    // 수열의 모든 원소를 순회
    // i: 현재 원소의 인덱스
    for (int i = 0; i < n; ++i) {
        // 스택이 비어있지 않고, 현재 원소가 스택의 top에 있는 원소보다 크다면
        // 스택s: 아직 오큰수를 찾지 못한 원소들의 인덱스 담고 있음
        while (!s.empty() && sequence[i] > sequence[s.top()]) {
            // 스택의 맨 위에 있는 원소가 현재 원소보다 작다면, 현재 원소가 그 원소의 오큰수
            nge[s.top()] = sequence[i];
            s.pop(); // 스택에서 원소를 제거
        }
        // 스택이 비어있거나 스택의 맨 위에 있는 원소가 현재 원소보다 크면, 현재 원소의 인덱스를 스택에 푸시
        s.push(i);
    }

    return nge;
}

int main() {
    int n;
    cin >> n; // 수열의 크기 입력 받기
    vector<int> sequence(n); // 수열을 저장할 벡터

    // 수열의 원소 입력 받기
    for (int i = 0; i < n; ++i) {
        cin >> sequence[i];
    }

    // 오큰수 계산
    vector<int> nge = find_next_greater_elements(sequence);

    // 결과 출력
    for (int i = 0; i < n; ++i) {
        cout << nge[i] << " ";
    }
    cout << "\n";

    return 0;
}
