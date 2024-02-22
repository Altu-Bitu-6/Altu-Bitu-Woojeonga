#include <iostream>
#include <tuple>
#include <cmath> // 절대값, 소숫점 처리를 위한 헤더 파일
using namespace std;

// 다이어트 결과 계산 함수
tuple<int, int, int> diet(int w0, int i0, int i, int a, int d, int t) {
    // w: 몸무게, m: 기초대사량
    int w1 = w0, m1 = i0; // 기초대사량 변화 고려하지 않는 경우의 체중, 기초대사량
    int w2 = w0, m2 = i0; // 기초대사량 변화 고려한 경우의 체중, 기초대사량

    while (d--) {
        // 체중 변화 계산: 일일 에너지 섭취량(i) - (기초대사량 + 일일 활동 대사량(a)) 만큼 변화
        // 일일 에너지 소비량 = 일일 기초 대사량 + 일일 활동 대사량
        w1 += i - (m1 + a); // 기초대사량 변화 고려X
        w2 += i - (m2 + a); // 기초대사량 변화 고려O

        // 기초대사량 변화 계산 (m2만 변화)
        if (abs(i - (m2 + a)) > t) {
            // (일일 에너지 섭취량 - 일일 에너지 소비량)의 절대값이 기초 대사량 변화 역치(t)를 초과하는 경우
            // 음수의 나눗셈에 주의 => float끼리의 나눗셈으로 수행하고 소숫점 버림
                                       
            m2 += float(i - (m2 + a)) / 2.0;
        }
    }
    // 계산된 체중, 기초대사량 반환
    return {w1, w2, m2};
}
int main() {
    int w0, i0, i, a;
    int d, t;
    int final_weight, final_meta;

    // 입력 받기
    // w0: 다이어트 전 체중, i0: 다이어트 전 일일 에너지 섭취량 및 기초대사량, t: 기초 대사량 변화 역치
    // d: 다이어트 기간, i: 다이어트 기간 일일 에너지 섭취량, a: 다이어트 기간 일일 활동 대사량
    cin >> w0 >> i0 >> t;
    cin >> d >> i >> a;

    // 다이어트 결과 계산
    tuple<int, int, int> tmp = diet(w0, i0, i, a, d, t);

    int w1 = get<0>(tmp), m1 = i0;          // 기초대사량 변화 고려 X, tmp 튜플의 첫 번째 요소를 추출
    int w2 = get<1>(tmp), m2 = get<2>(tmp); // 기초대사량 변화 고려 O 

    if (w1 <= 0) {
        // m1은 i0에서 변화하지 않고, i0는 0보다 크므로 기초대사량이 0kcal 이하가 되지 않음
        cout << "Danger Diet\n";
    } else {
        cout << w1 << " " << m1 << "\n";
    }

    if (w2 <= 0 || m2 <= 0) {
        cout << "Danger Diet";
    } else {
        cout << w2 << " " << m2 << " ";
        if (m2 < i0) {
            cout << "YOYO";
        } else {
            cout << "NO";
        }
    }
    return 0;
}