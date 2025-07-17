#include "BinarySearchTree.h"

BSTNode* BST_CreateNode(int NewData)
{
    BSTNode* NewNode = new BSTNode();

    NewNode->Left = nullptr;
    NewNode->Right = nullptr;
    NewNode->Data = NewData;

    return NewNode;
}

void BST_DestroyNode(BSTNode* Node)
{
    delete(Node);
}

void BST_DestroyTree(BSTNode* Tree)
{
    if (Tree->Right != nullptr)
        BST_DestroyNode(Tree->Right);
    if (Tree->Left != nullptr)
        BST_DestroyNode(Tree->Left);

    Tree->Left = nullptr;
    Tree->Right = nullptr;

    BST_DestroyNode(Tree);
}

BSTNode* BST_SearchNode(BSTNode* Tree, int Target)
{
    if (Tree == nullptr)
        return nullptr;

    if (Tree->Data == Target)
        return Tree;

    else if (Tree->Data > Target)
        BST_SearchNode(Tree->Left, Target);
    else
        BST_SearchNode(Tree->Right, Target);

}

BSTNode* BST_SearchMinNode(BSTNode* Tree)
{
    if (Tree == nullptr)
        return nullptr;

    if (Tree->Left == nullptr)
        return Tree;

    else
        return BST_SearchMinNode(Tree->Left);
}

void BST_InsertNode(BSTNode* Tree, BSTNode* Child)
{
    if (Tree->Data < Child->Data)
    {
        if (Tree->Right == nullptr)
            Tree->Right = Child;
        else
            BST_InsertNode(Tree->Right, Child);
    }
    else if (Tree->Data > Child->Data)
    {
        if (Tree->Left == nullptr)
            Tree->Left = Child;
        else
            BST_InsertNode(Tree->Left, Child);
    }
}

BSTNode* BST_RemoveNode(BSTNode* Tree, BSTNode* Parent, int Target)
{
    BSTNode* Removed = nullptr;
    if (Tree == nullptr)
    {
        return nullptr;
    }

    if (Tree->Data > Target)
        Removed = BST_RemoveNode(Tree->Left, Tree, Target);
    else if (Tree->Data < Target)
        Removed = BST_RemoveNode(Tree->Right, Tree, Target);
    else // 목표값을 찾은 경
    {
        Removed = Tree;

        // 잎 노드인 경우 바로 삭제
        if (Tree->Left == nullptr && Tree->Right == nullptr)
        {
            if (Parent->Left == Tree)
                Parent->Left = nullptr;
            else
                Parent->Right = nullptr;
        }
        else
        {
            // 자식이 양쪽 다 있는 경우
            if (Tree->Left != nullptr && Tree->Right != nullptr)
            {
                // 최솟값 노드를 찾아 제거한 뒤 현재의 노드에 위치시킨다.
                BSTNode* MinNode = BST_SearchMinNode(Tree->Right);
                MinNode = BST_RemoveNode(Tree, nullptr, MinNode->Data);
                Tree->Data = MinNode->Data;
            }
            else
            {
                // 자식이 한쪽만 있는 경우
                BSTNode* Temp = nullptr;
                if (Tree->Left != nullptr)
                    Temp = Tree->Left;
                else
                    Temp = Tree->Right;

                if (Parent->Left == Tree)
                    Parent->Left = Temp;
                else
                    Parent->Right = Temp;
            }
        }
    }

    return Removed;
}

void BST_InorderPrintTree(BSTNode* Node)
{
    if (Node == nullptr)
    {
        return;
    }

    // 왼쪽 하위 트리 출력
    BST_InorderPrintTree(Node->Left);

    // 뿌리 노드 출력
    cout << Node->Data << " ";

    // 오른쪽 하위 트리 출력
    BST_InorderPrintTree(Node->Right);
}
