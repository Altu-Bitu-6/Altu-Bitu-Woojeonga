#include <iostream>
#include <list>

using namespace std;

// 요세푸스 순열을 계산하는 함수
void josephus_sequence(int n, int k) {
    list<int> survivors;
    // 1부터 N까지의 사람들을 리스트에 초기화
    for (int i = 1; i <= n; i++) {
        survivors.push_back(i);
    }

    auto it = survivors.begin(); // 이터레이터 초기 위치
    cout << "<";
    while (!survivors.empty()) {
        // k번째 사람을 찾기 위해, 현재 위치에서부터 시작하여 k-1명의 사람을 건너뛰게 됨
        for (int count = 1; count < k; count++) {
            it++;
            // 리스트의 끝에 도달하면 다시 시작
            if (it == survivors.end()) it = survivors.begin();
        }
        
        // K번째 사람을 출력하고 리스트에서 제거
        cout << *it;
        it = survivors.erase(it); // 제거된 원소의 다음 원소를 가리키게 함
        if (!survivors.empty()) cout << ", ";

        // 리스트의 끝에 도달하면 다시 시작
        if (it == survivors.end()) it = survivors.begin();
    }
    cout << ">" << endl;
}

int main() {
    int n, k;
    // N과 K를 입력 받음
    cin >> n >> k;
    
    // 요세푸스 순열 계산
    josephus_sequence(n, k);
    
    return 0;
}
