#include <iostream>
#include <map>
#include <string>
using namespace std;

// 위치를 좌표계로 변환하는 함수
pair<int, int> pos_to_coord(string pos) { //pos: 체스판에서의 위치를 나타내는 문자열
    int x = pos[0] - 'A' + 1;
    int y = pos[1] - '1' + 1;
    return make_pair(x, y);
}

// 좌표를 위치 문자열로 변환하는 함수
string coord_to_pos(int x, int y) {
    string pos = "";
    pos += x + 'A' - 1;
    pos += y + '0';
    return pos;
}

// 킹과 돌의 이동 가능한 방향에 대한 맵
map<string, pair<int, int>> direction_map = {
    {"R", {1, 0}}, {"L", {-1, 0}}, {"B", {0, -1}}, {"T", {0, 1}},
    {"RT", {1, 1}}, {"LT", {-1, 1}}, {"RB", {1, -1}}, {"LB", {-1, -1}}
};

// 킹과 돌을 이동시키는 함수
void move_chess_piece(pair<int, int>& king, pair<int, int>& stone, string direction) {
    int dx = direction_map[direction].first;
    int dy = direction_map[direction].second;
    
    int new_king_x = king.first + dx;
    int new_king_y = king.second + dy;
    
    // 킹의 새 위치가 체스판 범위 내인지 확인
    if (new_king_x >= 1 && new_king_x <= 8 && new_king_y >= 1 && new_king_y <= 8) {
        // 돌이 킹의 새 위치에 있는 경우
        if (new_king_x == stone.first && new_king_y == stone.second) {
            int new_stone_x = stone.first + dx;
            int new_stone_y = stone.second + dy;
            
            // 돌의 새 위치도 체스판 범위 내인 경우만 이동
            if (new_stone_x >= 1 && new_stone_x <= 8 && new_stone_y >= 1 && new_stone_y <= 8) {
                stone.first = new_stone_x;
                stone.second = new_stone_y;
                king.first = new_king_x;
                king.second = new_king_y;
            }
        } else {
            // 돌이 없는 경우 킹만 이동
            king.first = new_king_x;
            king.second = new_king_y;
        }
    }
}

int main() {
    string king_pos, stone_pos, move_cmd;
    int move_count;
    cin >> king_pos >> stone_pos >> move_count;
    
    pair<int, int> king = pos_to_coord(king_pos);
    pair<int, int> stone = pos_to_coord(stone_pos);
    
    for (int i = 0; i < move_count; i++) {
        cin >> move_cmd;
        move_chess_piece(king, stone, move_cmd);
    }
    
    cout << coord_to_pos(king.first, king.second) << "\n";
    cout << coord_to_pos(stone.first, stone.second) << "\n";
    
    return 0;
}
