#include <iostream>
#include <queue>

using namespace std;

// 선물들을 처리하는 함수: 선물 추가 또는 가장 가치 있는 선물 반환
void process_gifts(priority_queue<int>& gifts, int num_gifts) {
    if (num_gifts == 0) {
        if (gifts.empty()) {
            cout << -1 << '\n'; // 큐가 비어있으면 -1 출력
        } else {
            cout << gifts.top() << '\n'; // 큐에서 가장 큰 요소(가장 가치 있는 선물) 출력
            gifts.pop(); // 해당 선물 제거
        }
    } else {
        int value;
        for (int i = 0; i < num_gifts; ++i) {
            cin >> value; // 선물 가치를 입력
            gifts.push(value); // 선물 가치를 우선순위 큐에 추가
        }
    }
}

int main() {
    int n; // 방문 횟수
    cin >> n;

    priority_queue<int> gifts; // 선물들을 저장할 우선순위 큐

    for (int i = 0; i < n; ++i) {
        int a; // 거점지에서 충전하는 선물의 개수 또는 아이들을 만난 표시(0)
        cin >> a;
        process_gifts(gifts, a); // 선물 처리 함수 호출
    }

    return 0;
}
