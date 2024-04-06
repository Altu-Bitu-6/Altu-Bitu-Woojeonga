#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_RELATIONS = 102; // 최대 관계 수

int number_of_people, query_person_a, query_person_b, number_of_relations;
vector<int> relationship_graph[MAX_RELATIONS]; // 관계 그래프
int kinship_distance[MAX_RELATIONS]; // 촌수 거리

void calculate_kinship_bfs(int start_person) {
    queue<int> bfs_queue;
    bfs_queue.push(start_person);
    kinship_distance[start_person] = 0; // 시작점의 촌수는 0

    while (!bfs_queue.empty()) {
        int current_person = bfs_queue.front();
        bfs_queue.pop();

        for (int related_person : relationship_graph[current_person]) {
            if (kinship_distance[related_person] == -1) { // 아직 방문하지 않은 경우
                kinship_distance[related_person] = kinship_distance[current_person] + 1;
                bfs_queue.push(related_person);
            }
        }
    }
}

int main() {
    cin >> number_of_people;
    cin >> query_person_a >> query_person_b;
    cin >> number_of_relations;

    fill_n(kinship_distance, MAX_RELATIONS, -1); // 촌수 거리를 -1로 초기화

    for (int i = 0; i < number_of_relations; ++i) {
        int person1, person2;
        cin >> person1 >> person2;
        relationship_graph[person1].push_back(person2);
        relationship_graph[person2].push_back(person1);
    }

    calculate_kinship_bfs(query_person_a);

    cout << kinship_distance[query_person_b] << "\n";

    return 0;
}
