#include <iostream>
using namespace std;
// 링크드 리스트 기반 스택
// 장점은 스택 용량에 제한을 두지 않아도 된다는 것

class Node
{
public:
	char* Data;
	Node* NextNode;

	Node(const char* Data)
		: Data(new char[sizeof(Data) + 1])
		, NextNode(nullptr)
	{
		strcpy_s(this->Data, sizeof(Data), Data);
	}

	~Node()
	{
		if (Data)
		{
			delete[] Data;
			Data = nullptr;
		}

		if (NextNode)
		{
			NextNode = nullptr;
		}
	}
};

class LinkedListStack
{
public:
	Node* List;
	Node* Top;

	LinkedListStack()
		: List(nullptr)
		, Top(nullptr)
	{
	}
};

void LLS_CreateStack(LinkedListStack** Stack)
{
	// 스택을 자유 저장소에 생성
	(*Stack) = new LinkedListStack();
}


void LLS_DestroyStack(LinkedListStack* Stack)
{
	Node* Current = Stack->List;
	while (Current != nullptr)
	{
		Node* Temp = Current;
		Current = Current->NextNode;
		delete(Temp);
	}

	Stack->Top = nullptr;
}

void LLS_Push(LinkedListStack* Stack, Node* NewNode)
{
	if (Stack->List == nullptr)
	{
		Stack->List = NewNode;
	}
	else
	{
		// 스택의 Top 위에 새 노드를 얹는다.
		Stack->Top->NextNode = NewNode;
	}

	// 스택의 Top 필드에 새 노드의 주소를 등록한다.
	Stack->Top = NewNode;
}

Node* LLS_Pop(LinkedListStack* Stack)
{
	// LLS_Pop() 함수가 반환할 최상위 노드 저장
	Node* TopNode = Stack->Top;

	if (Stack->List == Stack->Top)
	{
		Stack->List = nullptr;
		Stack->Top = nullptr;
	}

	else
	{
		// Top 아래에 있던 노드를 새로운 CurrentTop에 저장
		Node* CurrentTop = Stack->List;

		while (CurrentTop != nullptr && CurrentTop->NextNode != Stack->Top)
		{
			CurrentTop = CurrentTop->NextNode;
		}

		// CurrentTop을 Top에 저장
		if (CurrentTop)
		{
			Stack->Top = CurrentTop;
			CurrentTop->NextNode = nullptr;
		}
	}

	return TopNode;
}


int main()
{

	int i = 0;
	int Count = 0;
	Node* Popped;

	LinkedListStack* Stack;

	LLS_CreateStack(&Stack);

	LLS_Push(Stack, new Node("ASC"));
	LLS_Push(Stack, new Node("AVC"));
	LLS_Push(Stack, new Node("KOSD"));

	Popped = LLS_Pop(Stack);
	cout << Popped->Data << "\n";


	Popped = LLS_Pop(Stack);
	cout << Popped->Data << "\n";

	Popped = LLS_Pop(Stack);
	cout << Popped->Data << "\n";
	
	return 0;
}