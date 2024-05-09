#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 과자들을 조카 수에 맞게 분배할 수 있는지 확인
bool can_distribute(const vector<int>& snacks, int num_cousins, int length) {
    long long count = 0;
    for (int snack : snacks) {
        count += snack / length;
        if (count >= num_cousins) {
            return true;
        }
    }
    return false;
}

// 최대 과자 길이를 찾는 함수
int find_max_snack_length(const vector<int>& snacks, int num_cousins) {
    int left = 1;
    int right = *max_element(snacks.begin(), snacks.end());
    int answer = 0;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (can_distribute(snacks, num_cousins, mid)) {
            answer = mid; // 현재 길이를 저장하고, 더 긴 길이를 탐색
            left = mid + 1;
        } else {
            right = mid - 1; // 더 짧은 길이를 탐색
        }
    }
    return answer;
}

// 메인 함수: 입력을 처리하고 최대 길이 출력
int main() {
    int num_cousins, num_snacks;
    cin >> num_cousins >> num_snacks;
    
    vector<int> snacks(num_snacks);
    for (int i = 0; i < num_snacks; i++) {
        cin >> snacks[i];
    }
    
    int max_length = find_max_snack_length(snacks, num_cousins);
    cout << max_length << endl;
    
    return 0;
}
