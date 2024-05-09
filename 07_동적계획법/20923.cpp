#include <bits/stdc++.h>
using namespace std;

// 두 플레이어의 덱과 필드를 표현하기 위한 덱 변수들
deque<int> Deck[2], Ground[2];

// 카드의 수와 이동 횟수를 저장할 변수들
int NumberOfCards, NumberOfMoves;

// 승리 조건을 확인하는 함수
int WinCheck() {
    // 어느 한 플레이어의 필드 상단 카드가 5인지 확인
    if (Ground[0].size() && Ground[0].front() == 5) return 0;
    if (Ground[1].size() && Ground[1].front() == 5) return 0;
    
    // 양 플레이어의 필드 상단 카드 합이 5인지 확인
    if (Ground[0].size() && Ground[1].size() && Ground[0].front() + Ground[1].front() == 5) return 1;
    
    // 위 조건들에 해당하지 않으면 -1 반환
    return -1;
}

// 카드 게임 한 판을 시뮬레이션하는 함수
void PlayGame() {
    // 현재 차례를 나타내는 변수
    int Turn = 0;
    for (int i = 0; i < NumberOfMoves; ++i) {
        // 플레이어의 덱에서 가장 위에 있는 카드를 필드로 이동
        Ground[Turn].push_front(Deck[Turn].front());
        Deck[Turn].pop_front();
        
        // 현재 플레이어의 덱이 비었는지 확인
        if (Deck[Turn].empty()) {
            cout << (Turn ? "do" : "su") << '\n';
            return;
        }
        
        // 승리 조건 확인
        int Winner = WinCheck();
        if (Winner != -1) {
            // 승자가 있는 경우, 필드의 모든 카드를 승자의 덱으로 이동
            int Loser = 1 - Winner;
            while (Ground[Loser].size()) {
                Deck[Winner].push_back(Ground[Loser].back());
                Ground[Loser].pop_back();
            }
            while (Ground[Winner].size()) {
                Deck[Winner].push_back(Ground[Winner].back());
                Ground[Winner].pop_back();
            }
        }
        
        // 차례 교체
        Turn = 1 - Turn;
    }
    
    // 모든 이동 후, 덱의 크기를 기준으로 결과 결정
    if (Deck[0].size() > Deck[1].size()) cout << "do" << '\n';
    else if (Deck[0].size() < Deck[1].size()) cout << "su" << '\n';
    else cout << "dosu" << '\n';
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    // 카드 수와 이동 횟수 입력
    cin >> NumberOfCards >> NumberOfMoves;
    
    // 입력받은 카드로 덱 채우기
    for (int i = 0; i < NumberOfCards; ++i) {
        int CardForPlayerOne, CardForPlayerTwo;
        cin >> CardForPlayerOne >> CardForPlayerTwo;
        Deck[0].push_front(CardForPlayerOne);
        Deck[1].push_front(CardForPlayerTwo);
    }
    
    // 게임 플레이 함수 호출
    PlayGame();
    
    return 0;
}
