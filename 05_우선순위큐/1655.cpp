#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 중간값을 관리하는 클래스 선언
class MedianManager {
private:
    priority_queue<int> max_heap; // 작은 수를 저장하는 최대 힙
    priority_queue<int, vector<int>, greater<int>> min_heap; // 큰 수를 저장하는 최소 힙

public:
    // 새로운 수를 추가하는 함수
    void insert(int num) {
        // 먼저 최대 힙에 삽입
        // 중간값보다 작은 숫자들을 최대 힙에 모으기 위함
        if (max_heap.empty() || num < max_heap.top()) {// 최대 힙이 비어있거나, 새로운 숫자가 최대 힙의 최댓값보다 작거나 같은 경우, 이 숫자를 최대 힙에 삽입
            max_heap.push(num); 
        } else {
            min_heap.push(num);
        }

        // 힙들 간의 크기 조정
        if (max_heap.size() < min_heap.size()) {// 최소 힙의 크기가 최대 힙보다 크다면, 최소 힙의 최솟값(힙의 맨 위)을 최대 힙으로 옮기기
            max_heap.push(min_heap.top());
            min_heap.pop();
        } else if (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
    }

    // 현재 중간값을 가져오는 함수
    int get_median() {
        return max_heap.top();
    }
};

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 향상 위해
    cin.tie(NULL);

    int n; // 백준이가 외치는 정수의 개수
    cin >> n;

    MedianManager median_manager; // 중간값 관리 객체

    for (int i = 0; i < n; ++i) {
        int num; // 백준이가 외치는 정수
        cin >> num;
        median_manager.insert(num); // 수를 중간값 관리 객체에 삽입
        cout << median_manager.get_median() << '\n'; // 현재까지의 중간값 출력
    }

    return 0;
}
