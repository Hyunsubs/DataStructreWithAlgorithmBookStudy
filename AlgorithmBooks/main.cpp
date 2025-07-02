#include <iostream>

// 링크드 리스트
// 단점
// 각 노드마다 다음 노드를 가리켜야 하기 때문에 추가적으로 메모리를 소모한다.
// 특정 위치에 있는 노드에 접근하는데 필요한 비용이 매우크다
// 장점
// 새로운 노드의 추가 삽입, 삭제가 빠르다.
// 현재 노드의 다음 노드를 가져오는것에 비용이 발생하지 않는다.

// 사용처
// 삽입 삭제가 빈번히 일어나지만 조회가 드물게 일어나는곳


class Node
{
public:
	int data;
	Node* next;

	Node(int NewData)
		: data(NewData)
		, next(nullptr)
	{
	}
	
}; 


Node* SLL_CreateNode(int NewData)
{
	Node* NewNode = new Node(NewData);
	NewNode->next = nullptr;
	return NewNode;
}

void SLL_DestroyNode(Node* Node)
{
	delete Node;
	Node = nullptr;
}

void SLL_AppendNode(Node** Head, Node* NewNode)
{
	// 헤드 노드가 nullptr 이라면 새로운 노드가 Head가 된다.
	if ((*Head) == nullptr)
	{
		*Head = NewNode;
	}

	else
	{
		// 테일을 찾아 NewNode를 연결한다.
		Node* Tail = (*Head);

		while (Tail->next != nullptr)
		{
			Tail = Tail->next;
		}

		Tail->next = NewNode;
	}
}

Node* SLL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;
	while (Current != nullptr && (--Location) >= 0)
	{
		Current = Current->next;
	}
	return Current;
}

void SLL_RemoveNode(Node** Head, Node* Remove)
{
	if ((*Head) == Remove)
	{
		*Head = Remove->next;
	}

	else
	{
		Node* Current = *Head;
		while (Current != nullptr && Current->next != Remove)
		{
			Current = Current->next;
		}

		if (Current != nullptr)
		{
			Current->next = Remove->next;
		}
	}
}

void SLL_InsertBefore(Node** Head, Node* Current, Node* NewHead)
{
	if ((*Head)->next == Current)
	{
		(*Head)->next = NewHead;
		NewHead->next = Current;
	}
}

void SLL_DestroyAllNodes(Node** List)
{
	Node* Head = *List;
	while (Head != nullptr)
	{
		Node* NewHead = Head->next;
		std::cout << Head->data << " 노드 삭제 진행\n";
		delete Head;
		Head = NewHead;
	}

	std::cout << "모든 노드의 삭제가 완료되었습니다.\n";
}

int main()
{

	// 노드 순회 테스트
	Node* List = nullptr;
	Node* MyNode = nullptr;

	SLL_AppendNode(&List, SLL_CreateNode(117));
	SLL_AppendNode(&List, SLL_CreateNode(119));


	MyNode = SLL_GetNodeAt(List, 1); // 두번째 노드의 주소를 MyNode에 저장.
	SLL_InsertBefore(&List, MyNode, SLL_CreateNode(115));
	MyNode = SLL_GetNodeAt(List, 0); // 두번째 노드의 주소를 MyNode에 저장.
	std::cout << MyNode->data << "\n";
	MyNode = SLL_GetNodeAt(List, 1); // 두번째 노드의 주소를 MyNode에 저장.
	std::cout << MyNode->data << "\n";
	MyNode = SLL_GetNodeAt(List, 2); // 두번째 노드의 주소를 MyNode에 저장.
	std::cout << MyNode->data << "\n";

	SLL_DestroyAllNodes(&List);

	return 0;
}