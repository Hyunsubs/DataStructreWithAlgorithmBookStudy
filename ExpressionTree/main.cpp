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

	// 뿌리 노드 출력
	cout << Node->GetData();

	// 왼쪽 하위 트리 출력
	PreorderPrintTree(Node->GetLeft());

	// 오른쪽 하위 트리 출력
	PreorderPrintTree(Node->GetRight());
}

void PostorderPrintTree(Node* Node)
{
	if (Node == nullptr)
	{
		return;
	}

	// 왼쪽 하위 트리 출력
	PostorderPrintTree(Node->GetLeft());

	// 오른쪽 하위 트리 출력
	PostorderPrintTree(Node->GetRight());

	// 뿌리 노드 출력
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
		// 연산자인 경우
	case '+': case '-': case '*': case '/':
		Left = Evaluate(Tree->Left);
		Right = Evaluate(Tree->Right);

		if (Tree->Data == '+') { Result = Left + Right; }
		else if (Tree->Data == '-') { Result = Left - Right; }
		else if (Tree->Data == '*') { Result = Left * Right; }
		else if (Tree->Data == '/') { Result = Left / Right; }
		break;
		// 피연산자인 경우
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