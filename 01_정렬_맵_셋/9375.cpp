#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int T; // 테스트 케이스 수
    cin >> T;
    
    while (T--) {
        int n; // 의상 수
        cin >> n;
        
        map<string, int> clothes; // 의상 종류별 개수 저장
        for (int i = 0; i < n; ++i) {
            string name, type;
            cin >> name >> type; // 의상 이름과 종류 입력
            clothes[type]++; // 해당 종류의 의상 개수 증가
        }
        
        int result = 1; // 가능한 조합의 수 (초기값 1)
        for (auto it = clothes.begin(); it != clothes.end(); ++it) {
            result *= (it->second + 1); // 각 종류별 의상 개수 + 1(안 입는 경우)을 곱함
        }
        
        cout << result - 1 << endl; // 모두 안 입는 경우를 제외하고 출력
    }
    
    return 0;
}
