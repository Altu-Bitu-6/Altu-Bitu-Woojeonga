#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// 숫자 카드를 입력받아 unordered_set에 저장하여 반환하는 함수
unordered_set<int> input_cards(int card_count)
{
    unordered_set<int> cards;
    for (int i = 0; i < card_count; i++)
    {
        int card;
        cin >> card; // 카드 숫자 입력 받기
        cards.insert(card); // 입력받은 카드를 unordered_set에 삽입
    }
    return cards;
}

// 쿼리를 입력받아 vector에 저장하여 반환하는 함수
vector<int> input_queries(int query_count)
{
    vector<int> queries(query_count); // 쿼리 개수만큼 크기를 가진 vector 생성
    for (int i = 0; i < query_count; i++)
    {
        cin >> queries[i]; 
    }
    return queries;
}

// 상근이의 카드를 검사하여 쿼리 결과를 반환하는 함수
vector<int> check_sanggeun_cards(const unordered_set<int>& sanggeun_cards, const vector<int>& queries)
{
    vector<int> results;
    for (int query : queries)
    {
        if (sanggeun_cards.find(query) != sanggeun_cards.end()) 
        {
            results.push_back(1); // 상근이가 해당 카드를 가지고 있으면 1 추가
        }
        else
        {
            results.push_back(0); // 상근이가 해당 카드를 가지고 있지 않으면 0 추가
        }
    }
    return results;
}

// 결과 출력 함수
void print_results(const vector<int>& results)
{
    for (int result : results)
    {
        cout << result << " "; // 결과를 공백으로 구분하여 출력
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int card_count;
    cin >> card_count;
    unordered_set<int> sanggeun_cards = input_cards(card_count);

    int query_count;
    cin >> query_count;
    vector<int> queries = input_queries(query_count);

    vector<int> results = check_sanggeun_cards(sanggeun_cards, queries);
    print_results(results);

    return 0;
}
