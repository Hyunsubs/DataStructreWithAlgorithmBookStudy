#include <iostream>
using namespace std;

// LCRS
// ���� �ڽ� ������ ���� ����� Ʈ�� ����

class Node
{
	int Data;

	Node* LeftChild;
	Node* RightSibling;

public:
	Node(int Data)
		: Data(Data)
		, LeftChild(nullptr)
		, RightSibling(nullptr)
	{
		
	}


	~Node()
	{
		delete LeftChild;
		delete RightSibling;
	}

	int GetData()
	{
		return Data;
	}

	Node* GetLeftChild()
	{
		return LeftChild;
	}

	Node* GetRightSibling()
	{
		return RightSibling;
	}


	void AddChild(Node* Parent, Node* Child)
	{
		if (Parent->LeftChild == nullptr)
		{
			Parent->LeftChild = Child;
		}
		else
		{
			Node* TempNode = Parent->LeftChild;
			while (TempNode->RightSibling != nullptr)
			{
				TempNode = TempNode->RightSibling;
			}
			
			TempNode->RightSibling = Child;
		}
	}

	void PrintNodeAtLevel(int Level)
	{
		Node* TempNode = this;
		for (int i = 0; i < Level; i++)
		{
			if (TempNode->LeftChild)
			{
				TempNode = TempNode->LeftChild;
			}
			else
			{
				cout << "�ش� ���̴� �������� �ʽ��ϴ�.\n";
				return;
			}
		}
		
		while (TempNode->RightSibling)
		{
			cout << TempNode->Data << " ";
			TempNode = TempNode->RightSibling;
		}

		cout << TempNode->Data << " ";
		TempNode = TempNode->RightSibling;

		cout << "\n";

	}
};

void PrintTree(Node* Node, int Depth)
{
	// �鿩����
	int i = 0;
	for (i=0; i < Depth - 1; i++)
	{
		cout << "   "; // ���� 3ĭ
	}

	if (Depth > 0) // �ڽ� ��� ���� ǥ��
	{
		cout << "+--";
	}

	// ��� ������ ���
	cout << Node->GetData() << "\n";

	if (Node->GetLeftChild())
	{
		PrintTree(Node->GetLeftChild(), Depth + 1);
	}

	if (Node->GetRightSibling())
	{
		PrintTree(Node->GetRightSibling(), Depth);
	}
}



int main()
{
	Node* root = new Node(1);
	Node* Child = nullptr;
	root->AddChild(root, new Node(2));
	root->AddChild(root, Child = new Node(3));
	root->AddChild(root, Child = new Node(6));
	root->AddChild(root, Child = new Node(7));
	root->AddChild(root, Child = new Node(9));
	root->AddChild(Child , new Node(4));


	PrintTree(root, 0);
	root->PrintNodeAtLevel(1);

	delete root;  // �����ϰ� Ʈ�� ��ü �޸� ����



	return 0;
}