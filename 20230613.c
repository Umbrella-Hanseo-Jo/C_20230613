#include <stdio.h>
#include <stdlib.h>

// 이진 탐색 트리의 노드를 나타내는 구조체
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// 새로운 노드를 생성하는 함수
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 이진 탐색 트리에 노드를 삽입하는 함수
struct Node* insert(struct Node* node, int key) {
    // 트리가 비어있는 경우 새로운 노드를 생성하여 반환
    if (node == NULL)
        return createNode(key);
        
    // 삽입할 위치를 찾아 재귀적으로 삽입
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
        
    return node;
}

// 이진 탐색 트리를 중위 순회하는 함수
void inorderTraversal(struct Node* node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d ", node->key);
        inorderTraversal(node->right);
    }
}

int main() {
    struct Node* root = NULL;
    int keys[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(keys) / sizeof(keys[0]);
    
    // 주어진 키들을 이진 탐색 트리에 삽입
    for (int i = 0; i < n; i++)
        root = insert(root, keys[i]);
    
    // 중위 순회 결과 출력
    printf("중위 순회 결과: ");
    inorderTraversal(root);
    
    return 0;
}