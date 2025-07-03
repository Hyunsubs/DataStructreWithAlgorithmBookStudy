#include <iostream>


// 더블 링크드 리스트

class Node
{
public:
	int Data;
	Node* Prev;
	Node* Next;

	Node(int NewData) : 
		Data(NewData),
		Prev(nullptr),
		Next(nullptr)
	{
		
	}
};

// 노드 생성
Node* DLL_CreateNode(int NewData)
{
	Node* NewNode = new Node(NewData);

	NewNode->Data = NewData;
	NewNode->Prev = nullptr;
	NewNode->Next = nullptr;

	return NewNode;
}

// 노드 삭제
void DestroyNode(Node* Node)
{
	delete(Node);
}

void DLL_AppendNode(Node** Head, Node* NewNode)
{
	// 헤드 노드가 nullptr이라면 새로운 노드가 Head가 됨
	if ((*Head) == nullptr)
	{
		*Head = NewNode;
	}

	else
	{
		// 꼬리를 찾아 NewNode를 연결
		Node* Tail = (*Head);
		while (Tail->Next != nullptr)
		{
			Tail = Tail->Next;
		}

		Tail->Next = NewNode;
		NewNode->Prev = Tail; // Singly Linked List와 다른점 기존 테일을 새로운 테일의 Prev로 연결
	}
}

// 특정 위치 노드 가져오기(기존과 같은 코드를 사용함)
Node* DLL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;
	while (Current != nullptr && (--Location) >= 0)
	{
		Current = Current->Next;
	}
	
	return Current;
}

// 특정 노드를 리스트에서 제거
void DLL_RemoveNode(Node** Head, Node* Remove)
{
	// 제거할 노드가 Head인 경우
	if ((*Head) == Remove)
	{
		// Head의 다음 노드를 가리킴
		*Head = Remove->Next;
		// 다음 노드가 있는 경우
		if ((*Head) != nullptr)
		{
			// 이전 노드를 삭제할 것이기 때문의 다음 노드의 Prev는 nullptr이 돼야함
			(*Head)->Prev = nullptr;
		}

		// 삭제할 노드가 가리키는 Prev와 Next를 nullptr로 수정
		Remove->Prev = nullptr;
		Remove->Next = nullptr;
	}
	// Head 외에 노드
	else
	{
		Node* Temp = Remove;

		if (Remove->Prev != nullptr)
		{
			// 이전 노드가 가리키는 Next는 Remove할 노드가 가진 Next가 돼야함 
			Remove->Prev->Next = Temp->Next;
		}
		if (Remove->Next != nullptr)
		{
			// 삭제할 노드의 다음 노드는 Remove될 노드가 가진 Prev가 돼야함
			Remove->Next->Prev = Temp->Prev;
		}

		// Remove가 가지고 있는 기존 Prev와 Next의 주소를 nullptr로 수정하여 연결성 제거
		Remove->Prev = nullptr;
		Remove->Next = nullptr;
	}
}

// 노드 삽입
void DLL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->Next = Current->Next;
	NewNode->Prev = Current;

	if (Current->Next != nullptr)
	{
		Current->Next->Prev = NewNode;
		Current->Next = NewNode;
	}
}

// 노드 갯수 반환
int DLL_GetNodeCount(Node* Head) 
{
	unsigned int Count = 0;
	Node* Current = Head;

	while (Current != nullptr)
	{
		Current = Current->Next; 
		Count++;
	}

	return Count;
}

// 리스트의 역순 출력
void PrintReverse(Node* Head)
{
	Node* Current = Head;

	while (Current->Next != nullptr)
	{
		Current = Current->Next;
	}

	while (Current->Prev != nullptr)
	{
		std::cout << Current->Data << " ";
		Current = Current->Prev;
	}

	std::cout << Current->Data << " ";
}

int main()
{
	Node* List = nullptr;
	for (int i = 0; i < 20; i++)
	{
		Node* NewNode = nullptr;
		NewNode = DLL_CreateNode(i);
		DLL_AppendNode(&List, NewNode);
	}

	PrintReverse(List);



	return 0;
}