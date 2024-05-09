#include <iostream>
#include <queue>

using namespace std;

int main() {
	// 입출력 성능 향상을 위한 설정
	ios::sync_with_stdio(false); // 입출력 버퍼 분리
	cin.tie(NULL);              
	cout.tie(NULL);              // cout의 flush가 자동으로 호출되지 않도록

	int n, num;
	priority_queue<int, vector<int>, greater<int>> pq; // 최소 힙 정의

	// 입력 받을 숫자의 개수 n을 입력 받기
	cin >> n;

	// n * n만큼의 수를 입력 받아 처리하는 과정
	for (int i = 0; i < n * n; i++) {
		// 숫자 입력 받기
		cin >> num;
		// 입력 받은 숫자를 최소 힙에 추가
		pq.push(num);

		// 만약 최소 힙의 크기가 n보다 커지면,
		// 최소 힙의 최상단에 있는 가장 작은 값을 제거
		if (pq.size() > n) {
			pq.pop();
		}
	}

	// n번째로 큰 수를 출력
	// pq.top()은 최소 힙의 최상단에 있는 가장 작은 값이며,
	// 이는 입력된 수들 중 n번째로 큰 수에 해당
	cout << pq.top();

	return 0; 
}
