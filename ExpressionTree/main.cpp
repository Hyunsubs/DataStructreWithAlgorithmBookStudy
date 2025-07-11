#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
	int Data;
	Node* Left;
	Node* Right;

public:
	Node(int Data)
		: Data(Data)
		, Left(nullptr)
		, Right(nullptr)
	{

	}

	~Node()
	{
		if (Left)
		{
			delete(Left);
		}

		if (Right)
		{
			delete(Right);
		}
	}

	int GetData()
	{
		return Data;
	}

	Node* GetLeft() { return Left; }
	Node* GetRight() { return Right; }
};

void PreorderPrintTree(Node* Node)
{
	if (Node == nullptr)
	{
		return;
	}

	// �Ѹ� ��� ���
	cout << Node->GetData();

	// ���� ���� Ʈ�� ���
	PreorderPrintTree(Node->GetLeft());

	// ������ ���� Ʈ�� ���
	PreorderPrintTree(Node->GetRight());
}

void PostorderPrintTree(Node* Node)
{
	if (Node == nullptr)
	{
		return;
	}

	// ���� ���� Ʈ�� ���
	PostorderPrintTree(Node->GetLeft());

	// ������ ���� Ʈ�� ���
	PostorderPrintTree(Node->GetRight());

	// �Ѹ� ��� ���
	cout << Node->GetData();

}

void InorderPrintTree(Node* Node)
{
	if (Node == nullptr)
	{
		return;
	}

	InorderPrintTree(Node->GetLeft());

	cout << Node->GetData();

	InorderPrintTree(Node->GetRight());
}

void BuildExpressionTree(string& Expression, Node** _Node)
{
	int length = strlen(Expression.c_str());
	char Token = Expression[length - 1];
	Expression[length - 1] = '\0';

	switch (Token)
	{
	case '+': case '-': case '*': case '/':
		(*_Node) = new Node(Token);
		BuildExpressionTree(Expression, &(*_Node)->Right);
		BuildExpressionTree(Expression, &(*_Node)->Left);
		break;
	default:
		(*_Node) = new Node(Token);
		break;

	}
}

double Evaluate(Node* Tree)
{
	char Temp[2];

	double Left = 0;
	double Right = 0;
	double Result = 0;

	if (Tree == nullptr)
	{
		return 0;
	}

	switch (Tree->Data)
	{
		// �������� ���
	case '+': case '-': case '*': case '/':
		Left = Evaluate(Tree->Left);
		Right = Evaluate(Tree->Right);

		if (Tree->Data == '+') { Result = Left + Right; }
		else if (Tree->Data == '-') { Result = Left - Right; }
		else if (Tree->Data == '*') { Result = Left * Right; }
		else if (Tree->Data == '/') { Result = Left / Right; }
		break;
		// �ǿ������� ���
	default:
		memset(Temp, 0, sizeof(Temp));
		Temp[0] = Tree->Data;
		Result = atof(Temp);
		break;
	}

	return Result;
}


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Node* Root = nullptr;

	string PostfixExpression = "71*52-/";
	BuildExpressionTree(PostfixExpression, &Root);

	cout << Evaluate(Root) << "\n";

	delete(Root);

	return 0;
}