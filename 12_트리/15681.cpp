#include<iostream>
#include<vector>
#include<map>

using namespace std;


/**
 * DFS를 사용하여 트리를 탐색하고 서브트리의 정점 수를 계산하는 함수
 * param cur: 현재 탐색 중인 정점
 * prev: 이전에 탐색한 정점 (부모 노드)
 * tree: 트리의 인접 리스트
 * dp: 각 정점을 루트로 하는 서브트리의 정점 수를 저장하는 배열
 */

void dfs(int cur, int prev, vector<vector<int>>& tree, vector<int>& dp) {
    // 현재 정점의 자식 노드들을 순회
    for (int i = 0; i < tree[cur].size(); i++) {
        // 이전 정점 (부모 노드)로 돌아가는 것을 방지
        if (tree[cur][i] == prev) {
            continue;
        }
        // 자식 노드를 탐색
        dfs(tree[cur][i], cur, tree, dp);
        // 현재 정점의 dp 값에 자식 노드의 서브트리 크기를 더함
        dp[cur] += dp[tree[cur][i]];
    }
    return;
}

int main() {
    // 입출력 속도 향상을 위한 설정
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 입력 변수 선언
    int n, r, q, u, v;
    // 트리의 정점 개수, 루트 정점, 쿼리 개수 입력
    cin >> n >> r >> q;
    
    // 트리를 인접 리스트 형태로 저장하기 위한 벡터 초기화
    vector<vector<int>> tree(n + 1, vector<int>(0));
    
    // 트리의 간선 정보를 입력 받아 인접 리스트로 변환
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    // 각 정점을 루트로 하는 서브트리의 정점 수를 저장하는 배열 초기화
    // 자신도 자신을 루트로 하는 서브트리에 포함되므로 초기값을 1로 설정
    vector<int> dp(n + 1, 1);
    // 루트 정점에서 DFS 탐색 시작
    dfs(r, 0, tree, dp);

    // 쿼리 처리
    while (q--) {
        // 쿼리로 주어진 정점 입력
        cin >> u;
        // 해당 정점을 루트로 하는 서브트리의 정점 수 출력
        cout << dp[u] << '\n';
    }

    return 0;
}
