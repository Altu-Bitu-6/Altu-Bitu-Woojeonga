#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 자리수 합 계산 함수
int sumNum(const string& s){
    int sum = 0;
    for (char c : s){ // s 문자열 내의 문자를 돌면서
        if(isdigit(c)) sum += c - '0'; // 숫자인지 판단, 숫자 문자라면 정수값으로
    }
    return sum;

}

// 비교 함수
bool cmp(const string& A, const string& B){
    // 길이는 짧은 것이 앞
    if(A.length() != B.length()){
        return A.length() < B.length();
    }
    // 길이 같으면, 자리수 합 작은 것이 앞
    int sumA = sumNum(A);
    int sumB = sumNum(B);
    if(sumA != sumB){
        return sumA < sumB;
    }
    // 자리수 합도 같으면, 사전순
    return A < B;

}

int main() {
    int N; // N: 기타 개수
    cin >> N;
    vector<string> serials(N); // string 타입 저장할 수 있는 벡터 serial 선언

    for(int i = 0; i < N; ++i){
        cin >> serials[i]; //시리얼 번호
    }

    sort(serials.begin(), serials.end(), cmp);

    for(const string& serial : serials){
        cout << serial << '\n';
    }
    return 0;


}