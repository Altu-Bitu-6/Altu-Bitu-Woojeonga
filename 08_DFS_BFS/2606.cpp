#include <iostream>
#include <vector>
using namespace std;

const int MAX_COMPUTERS = 100; // 최대 컴퓨터 수
vector<int> network[MAX_COMPUTERS + 1]; // 네트워크 상의 연결 정보
bool visited[MAX_COMPUTERS + 1]; // 각 컴퓨터의 방문 여부

// DFS를 사용하여 네트워크 상의 연결된 컴퓨터를 탐색
int dfs(int start) {
    visited[start] = true;
    int infected = 1; // 시작 컴퓨터도 감염된 것으로 카운트
    for (int i = 0; i < network[start].size(); i++) {
        int next = network[start][i];
        if (!visited[next]) {
            infected += dfs(next);
        }
    }
    return infected;
}

int main() {
    int number_of_computers; // 컴퓨터의 수
    int number_of_connections; // 네트워크 상에서 직접 연결된 컴퓨터 쌍의 수

    cin >> number_of_computers;
    cin >> number_of_connections;

    for (int i = 0; i < number_of_connections; i++) {
        int computer1, computer2;
        cin >> computer1 >> computer2;
        network[computer1].push_back(computer2);
        network[computer2].push_back(computer1);
    }

    // 1번 컴퓨터부터 탐색을 시작하므로, DFS 결과에서 1을 빼서 출력 (1번 컴퓨터 제외)
    cout << dfs(1) - 1 << "\n";

    return 0;
}
