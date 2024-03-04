#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000000; // 최대 범위 설정
vector<bool> is_prime(MAX + 1, true); // 소수 판별을 위한 벡터, 초기값 true
vector<int> primes; // 소수만 담을 벡터(시간 초과로 추가)

// 소수를 찾는 함수
void findfunc() {
    is_prime[0] = is_prime[1] = false; // 0과 1은 소수 X
    for (int i = 2; i * i <= MAX; i++) { // 합성수: 적어도 하나의 소수인 약수를 가짐.(합성수를 구성하는 두 약수 중 하나는 반드시 제곱근보다 작거나 같고, 다른 하나는 제곱근보다 크거나 같음)
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX; j += i) { // i의 배수는 소수가 아님
                is_prime[j] = false; 
            }
        }
    }
    // 소수 리스트 생성
    for (int i = 2; i <= MAX; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}


// 골드바흐 추측을 검증하는 함수
void verify_goldbach(int n) {
    for (int i = 0; i < primes.size() && primes[i] <= n / 2; i++) {
        int a = primes[i]; // a: 현재 순회 중인 소수
        int b = n - a; // b: a와 더했을 때, n이 되는 수
        if (is_prime[b]) {
            cout << n << " = " << a << " + " << b << "\n";
            return;
        }
    }
    cout << "Goldbach's conjecture is wrong." << "\n";
}

int main() {
    // 표준 입출력과 C의 입출력간 동기화 비활성화
    ios_base::sync_with_stdio(false); // C++ IO 속도 향상 위함
    cin.tie(NULL); // cin과 cout의 tie를 끊음

    findfunc(); // 소수 찾기
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break; // 0이 입력되면 종료
        verify_goldbach(n); // 골드바흐 추측 검증
    }
    return 0;
}
