#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


// 데이터를 담을 노드 구조
class Node 
{
public:
	int Data;
};

// 스택 구조
// 용량과 최상위 노드 위치 그리고 노드의 배열 정보를 갖고 있어야 함
class ArrayStack
{
public:
	int Capacity;
	int Top;
	Node* Nodes;

	~ArrayStack() 
	{
		if (Nodes)
		{
			delete[] Nodes;
		}
	}
};

// 스택 생성
void AS_CreateStack(ArrayStack** Stack, int Capacity)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// 스택을 자유 저장소에 생성
	(*Stack) = new ArrayStack();

	// 입력된 Capacity 만큼의 노드를 자유 저장소에 생성
	(*Stack)->Nodes = new Node[Capacity];

	// Capacity 및 Top 초기화 -1은 비었음을 의미함
	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = -1;
}

// 스택 삭제
void AS_DestoryStack(ArrayStack* Stack)
{
	// 스택을 자유 저장소에서 해제
	// 내부 노드는 소멸자에서 지우도록 책 내용과 코드 다르게 변경
	delete(Stack);
}

// 노드 삽입 연산
void AS_Push(ArrayStack* Stack, int Data)
{
	Stack->Top++;
	Stack->Nodes[Stack->Top].Data = Data;
}

// 노드 제거 연산 (제거되기전 최상위 값을 반환해야함)
int AS_Pop(ArrayStack* Stack)
{
	return Stack->Nodes[(Stack->Top)--].Data;
}

bool AS_IsEmpty(ArrayStack* Stack)
{
	return Stack->Top > - 1 ? true : false;
}

int AS_Top(ArrayStack* Stack)
{
	return Stack->Nodes[(Stack->Top)].Data;
}

int AS_GetSize(ArrayStack* Stack)
{
	return (Stack->Top) + 1;
}

bool AS_IsFull(ArrayStack* Stack)
{
	return Stack->Top + 1 == Stack->Capacity;
}

int main()
{
	int i = 0;
	ArrayStack* Stack = nullptr;
	
	AS_CreateStack(&Stack, 10);

	AS_Push(Stack, 3);
	AS_Push(Stack, 5);
	AS_Push(Stack, 7);
	AS_Push(Stack, 9);
	AS_Push(Stack, 12);
	AS_Push(Stack, 12);
	AS_Push(Stack, 12);
	AS_Push(Stack, 12);
	AS_Push(Stack, 12);
	AS_Push(Stack, 12);

	std::cout << "Capacity : " << Stack->Capacity << " Size : " << AS_GetSize(Stack) << " Top : " << AS_Top(Stack) << "\n";
	AS_IsFull(Stack) ? std::cout << "Stack Is Full now\n" : std::cout << "Stack Is not Full\n";
	AS_DestoryStack(Stack);


	return 0;
}