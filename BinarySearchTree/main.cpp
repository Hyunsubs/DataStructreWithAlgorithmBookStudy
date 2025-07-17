#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main()
{
    // Ʈ�� ��Ʈ ����
    BSTNode* Root = BST_CreateNode(50);

    // Ʈ���� ��� ����
    BST_InsertNode(Root, BST_CreateNode(30));
    BST_InsertNode(Root, BST_CreateNode(70));
    BST_InsertNode(Root, BST_CreateNode(20));
    BST_InsertNode(Root, BST_CreateNode(40));
    BST_InsertNode(Root, BST_CreateNode(60));
    BST_InsertNode(Root, BST_CreateNode(80));

    // ���� ��ȸ ��� (�������� ��� ����: 20 30 40 50 60 70 80)
    cout << "Inorder Traversal: ";
    BST_InorderPrintTree(Root);
    cout << endl;

    // Ư�� ��� Ž�� �׽�Ʈ
    int searchValue = 60;
    BSTNode* searchResult = BST_SearchNode(Root, searchValue);
    if (searchResult != nullptr)
        cout << "Search " << searchValue << ": Found!" << endl;
    else
        cout << "Search " << searchValue << ": Not Found!" << endl;

    // �ּҰ� ��� ã��
    BSTNode* minNode = BST_SearchMinNode(Root);
    if (minNode != nullptr)
        cout << "Min Value in BST: " << minNode->Data << endl;

    // ��� ���� �׽�Ʈ
    cout << "Removing node with value 70" << endl;
    BST_RemoveNode(Root, nullptr, 70);  // ���� �׽�Ʈ

    // �ٽ� ���� ��ȸ ���
    cout << "Inorder Traversal after deletion: ";
    BST_InorderPrintTree(Root);
    cout << endl;

    // Ʈ�� ��ü ����
    BST_DestroyTree(Root);

    return 0;
}
