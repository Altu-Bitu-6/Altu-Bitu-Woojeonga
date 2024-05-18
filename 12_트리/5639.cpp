#include <iostream>
#include <vector>
using namespace std;

// 노드 구조체 정의
struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

// 새로운 노드를 트리에 삽입하는 함수
Node* insert_node(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }
    if (key < root->key) {
        root->left = insert_node(root->left, key);
    } else {
        root->right = insert_node(root->right, key);
    }
    return root;
}

// 후위 순회를 수행하는 함수
void postorder_traversal(Node* root, vector<int>& result) {
    if (root == nullptr) {
        return;
    }
    postorder_traversal(root->left, result);
    postorder_traversal(root->right, result);
    result.push_back(root->key);
}

int main() {
    vector<int> preorder;
    int key;

    // 입력 (전위 순회 결과)
    while (cin >> key) {
        preorder.push_back(key);
    }

    // 이진 검색 트리 생성
    Node* root = nullptr;
    for (int k : preorder) {
        root = insert_node(root, k);
    }

    // 후위 순회 결과 저장
    vector<int> postorder;
    postorder_traversal(root, postorder);

    // 후위 순회 결과 출력
    for (int k : postorder) {
        cout << k << endl;
    }

    return 0;
}
