#include <iostream>
#include <vector>

const int MAX_SUSHI_TYPE = 3001; // 초밥 종류의 최대 개수 + 1

// 최대 유니크 초밥 수를 계산하는 함수
int max_unique_sushi(const std::vector<int>& sushi_belt, int n, int d, int k, int coupon) {
    std::vector<int> sushi_count(MAX_SUSHI_TYPE, 0); // 각 초밥의 개수를 저장하는 배열
    int unique_count = 0, max_unique = 0; // 현재 유니크 초밥 수와 최대 유니크 초밥 수
    
    // 슬라이딩 윈도우 초기화
    for (int i = 0; i < k; ++i) {
        if (sushi_count[sushi_belt[i]]++ == 0) { // 해당 초밥의 수를 늘리고 처음 나온 것이면 유니크 수 증가
            ++unique_count;
        }
    }
    
    // 쿠폰으로 주어진 초밥이 초기 윈도우에 없으면 쿠폰 초밥 추가
    if (sushi_count[coupon] == 0) {
        max_unique = unique_count + 1;
    } else {
        max_unique = unique_count;
    }
    
    // 슬라이딩 윈도우를 움직이면서 초밥 최대 종류 수 계산
    for (int i = 1; i < n; ++i) {
        // 윈도우에서 벗어나는 초밥 제거
        if (--sushi_count[sushi_belt[i - 1]] == 0) {
            --unique_count;
        }
        
        // 새로운 초밥 윈도우에 추가
        int next_index = (i + k - 1) % n; // 원형이므로 모듈로 연산 사용
        if (sushi_count[sushi_belt[next_index]]++ == 0) {
            ++unique_count;
        }
        
        // 쿠폰 초밥을 포함한 최대 종류 수 계산
        if (sushi_count[coupon] == 0) {
            max_unique = std::max(max_unique, unique_count + 1);
        } else {
            max_unique = std::max(max_unique, unique_count);
        }
    }
    
    return max_unique;
}

int main() {
    int n, d, k, c;
    std::cin >> n >> d >> k >> c; // 사용자 입력 받기
    std::vector<int> sushi_belt(n); // 초밥 벨트 정보
    
    for (int i = 0; i < n; ++i) {
        std::cin >> sushi_belt[i]; // 초밥 벨트 종류 입력 받기
    }
    
    std::cout << max_unique_sushi(sushi_belt, n, d, k, c) << std::endl; // 결과 출력
    
    return 0;
}
