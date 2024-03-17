#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

// 문자의 빈도수를 비교하는 함수
bool areFrequenciesSimilar(const string& word1, const string& word2) {
    if (abs(int(word1.length()) - int(word2.length())) > 1) {
        return false; // 길이 차이가 1보다 크면 두 단어가 비슷할 수 없음
    }

    vector<int> freq1(26, 0), freq2(26, 0);

    // 각 단어의 문자 빈도수 계산
    for (char c : word1) freq1[c - 'A']++;
    for (char c : word2) freq2[c - 'A']++;

    int diffCount = 0; // 빈도수 차이가 나는 문자의 수
    for (int i = 0; i < 26; i++) {
        diffCount += abs(freq1[i] - freq2[i]);
    }

    // 완전히 같거나, 한 문자만큼의 차이를 허용
    return diffCount == 0 || diffCount == 1 || (diffCount == 2 && word1.length() == word2.length());
}

int main() {
    int N;
    cin >> N;

    vector<string> words(N);
    for (int i = 0; i < N; ++i) {
        cin >> words[i];
    }

    int similarWords = 0;
    for (int i = 1; i < N; ++i) {
        if (areFrequenciesSimilar(words[0], words[i])) {
            similarWords++;
        }
    }

    cout << similarWords << "\n";

    return 0;
}
