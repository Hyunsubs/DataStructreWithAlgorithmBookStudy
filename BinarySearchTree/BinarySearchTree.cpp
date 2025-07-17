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
    else // ��ǥ���� ã�� ��
    {
        Removed = Tree;

        // �� ����� ��� �ٷ� ����
        if (Tree->Left == nullptr && Tree->Right == nullptr)
        {
            if (Parent->Left == Tree)
                Parent->Left = nullptr;
            else
                Parent->Right = nullptr;
        }
        else
        {
            // �ڽ��� ���� �� �ִ� ���
            if (Tree->Left != nullptr && Tree->Right != nullptr)
            {
                // �ּڰ� ��带 ã�� ������ �� ������ ��忡 ��ġ��Ų��.
                BSTNode* MinNode = BST_SearchMinNode(Tree->Right);
                MinNode = BST_RemoveNode(Tree, nullptr, MinNode->Data);
                Tree->Data = MinNode->Data;
            }
            else
            {
                // �ڽ��� ���ʸ� �ִ� ���
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

    // ���� ���� Ʈ�� ���
    BST_InorderPrintTree(Node->Left);

    // �Ѹ� ��� ���
    cout << Node->Data << " ";

    // ������ ���� Ʈ�� ���
    BST_InorderPrintTree(Node->Right);
}
