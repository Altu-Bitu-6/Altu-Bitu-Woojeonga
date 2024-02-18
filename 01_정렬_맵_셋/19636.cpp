#include <iostream>
using namespace std;

int main() {
    int W0, I0, T, D, I, A;
    cin >> W0 >> I0 >> T >> D >> I >> A;

    // 일일 기초 대사량 변화를 고려하지 않은 경우
    int noChangeWeight = W0 + (I - (I0 + A)) * D; // 예상 체중
    if (noChangeWeight <= 0) { // 예상 체중이 0 이하라면
        cout << "Danger Diet\n";
    } else {
        cout << noChangeWeight << " " << I0 << endl; // 예상 체중 및 일일 기초 대사량 출력
    }

    // 일일 기초 대사량 변화를 고려한 경우
    int changeWeight = W0, changeI = I0;
    bool isDead = false, yoyo = false;
    for (int day = 0; day < D; ++day) {
        int energyDiff = I - (changeI + A);
        changeWeight += energyDiff; // 체중 변화
        if (abs(energyDiff) > T) { // 기초 대사량 변화 역치 초과하면,
            changeI += energyDiff / 2; // 일일 기초 대사량 변화
        }
        if (changeWeight <= 0 || changeI <= 0) { // 사망 조건
            isDead = true;
            break;
        }
    }

    if (isDead) {
        cout << "Danger Diet\n";
    } else {
        // 요요 현상 판단
        if (changeI + A < I0) {
            yoyo = true;
        }
        cout << changeWeight << " " << changeI << " " << (yoyo ? "YOYO" : "NO") << endl;
    }

    return 0;
}