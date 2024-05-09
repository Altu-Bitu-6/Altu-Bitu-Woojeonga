#include <iostream>
#include <vector>
#include <cmath>

// 행성들의 속도 배열과 현재 행성의 인덱스를 받아 최소 시작 속도를 계산하는 함수
long long calculate_minimum_speed(const std::vector<int>& planet_speeds) {
    long long required_speed = planet_speeds.back(); // 마지막 행성에서 요구되는 속도로 초기화

    // 마지막 행성부터 시작하여 각 행성으로 돌아가면서 요구되는 속도를 업데이트
    for (int i = planet_speeds.size() - 2; i >= 0; --i) {
        required_speed = static_cast<long long>(std::ceil(required_speed / static_cast<double>(planet_speeds[i]))) * planet_speeds[i];
    }

    return required_speed; // 계산된 최소 시작 속도를 반환
}

int main() {
    std::ios_base::sync_with_stdio(false); // 입출력 성능 향상을 위한 설정
    std::cin.tie(nullptr);

    int number_of_planets; // 행성의 수를 저장할 변수
    std::cin >> number_of_planets;

    std::vector<int> planet_speeds(number_of_planets); // 각 행성으로 이동하기 위한 속도를 저장할 벡터
    for (int i = 0; i < number_of_planets; ++i) {
        std::cin >> planet_speeds[i]; // 속도 입력
    }

    long long minimum_speed = calculate_minimum_speed(planet_speeds); // 최소 속도 계산

    std::cout << minimum_speed << '\n'; // 결과 출력

    return 0;
}
