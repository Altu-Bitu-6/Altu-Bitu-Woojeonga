#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> numbers;    // 입력받은 수를 저장하는 벡터
vector<int> sequence;   // 현재 조합을 저장하는 벡터

// 수열을 만들기 위한 재귀 함수
void make_sequence(int index, int m) {
    if (index == m) { // 기저 조건: 수열의 길이가 M과 같을 때
        for (int num : sequence) {
            cout << num << " ";
        }
        cout << '\n';
        return;
    }

    int last_used = 0; // 이전에 사용한 수를 저장하는 변수
    for (int i = 0; i < numbers.size(); ++i) {
        // 같은 깊이에서 같은 수를 연속하여 사용하지 않도록
        if (last_used != numbers[i]) {
            last_used = numbers[i]; // 현재 수를 마지막으로 사용한 수로 설정
            sequence[index] = numbers[i]; // 수열에 현재 수 추가
            make_sequence(index + 1, m); // 다음 수 추가
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    numbers.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i]; // 수 입력 받기
    }

    // 수를 정렬하여 중복 제거를 용이하게 함
    sort(numbers.begin(), numbers.end());
    
    sequence.resize(m); // M의 크기에 맞게 수열 벡터를 조정

    make_sequence(0, m); // 수열 생성 시작

    return 0;
}
