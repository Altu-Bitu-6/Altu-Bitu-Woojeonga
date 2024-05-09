#include <iostream>

using namespace std;

// 육각형의 변의 방향과 길이를 저장하는 구조체를 pair<int, int> 형태로 선언
pair<int, int> li[12];

// 육각형의 영역 너비를 계산하는 함수
int findArea() {
    int big_square; // 전체 사각형의 넓이를 저장할 변수
    int small_square; // 작은 사각형의 넓이를 저장할 변수

    // 6개의 변을 돌면서 육각형의 영역을 계산
    for (int i = 0; i < 9; i++) {
        // 현재 변과 그 다음 변이 같은 방향으로 이어지는 경우
        if (li[i].first == li[i + 2].first && li[i + 1].first == li[i + 3].first) {
            // 전체 사각형의 넓이는 두 변의 길이를 곱한 값
            big_square = (li[i].second + li[i + 2].second) * (li[i + 1].second + li[i + 3].second);
            // 작은 사각형의 넓이는 두 변의 길이를 곱한 값
            small_square = li[i + 2].second * li[i + 1].second;
        }
    }
    // 전체 사각형에서 작은 사각형의 넓이를 뺀 값이 육각형의 영역 너비
    return big_square - small_square;
}

int main() {
    int k; // 육각형의 개수를 저장할 변수
    cin >> k; // 육각형의 개수를 입력받음

    int direction, length;
    // 육각형의 변의 방향과 길이를 입력받아 배열에 저장
    for (int i = 0; i < 6; i++) {
        cin >> direction >> length;
        li[i] = {direction, length};
    }

    // 입력된 6개의 변을 이어붙여서 총 12개의 변을 만듦
    for (int i = 0; i < 6; i++) {
        li[i + 6] = li[i];
    }

    // 육각형의 영역 너비를 계산하고, 육각형의 개수와 곱하여 출력
    int area = findArea();
    cout << k * area << "\n";
    
    return 0;
}
