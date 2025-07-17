#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main()
{
    // 트리 루트 생성
    BSTNode* Root = BST_CreateNode(50);

    // 트리에 노드 삽입
    BST_InsertNode(Root, BST_CreateNode(30));
    BST_InsertNode(Root, BST_CreateNode(70));
    BST_InsertNode(Root, BST_CreateNode(20));
    BST_InsertNode(Root, BST_CreateNode(40));
    BST_InsertNode(Root, BST_CreateNode(60));
    BST_InsertNode(Root, BST_CreateNode(80));

    // 중위 순회 출력 (오름차순 출력 예상: 20 30 40 50 60 70 80)
    cout << "Inorder Traversal: ";
    BST_InorderPrintTree(Root);
    cout << endl;

    // 특정 노드 탐색 테스트
    int searchValue = 60;
    BSTNode* searchResult = BST_SearchNode(Root, searchValue);
    if (searchResult != nullptr)
        cout << "Search " << searchValue << ": Found!" << endl;
    else
        cout << "Search " << searchValue << ": Not Found!" << endl;

    // 최소값 노드 찾기
    BSTNode* minNode = BST_SearchMinNode(Root);
    if (minNode != nullptr)
        cout << "Min Value in BST: " << minNode->Data << endl;

    // 노드 삭제 테스트
    cout << "Removing node with value 70" << endl;
    BST_RemoveNode(Root, nullptr, 70);  // 삭제 테스트

    // 다시 중위 순회 출력
    cout << "Inorder Traversal after deletion: ";
    BST_InorderPrintTree(Root);
    cout << endl;

    // 트리 전체 삭제
    BST_DestroyTree(Root);

    return 0;
}
