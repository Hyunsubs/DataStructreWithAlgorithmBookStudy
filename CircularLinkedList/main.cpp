#include "CircularDoublyLinkedList.h"

// 환형 링크드 리스트(Circular Linked List)
// 그리스 신화에 등장하는 우로보로스처럼 머리가 꼬리를 물고 있는 형태임
// 즉 Head->Prev = Tail  Tail->Next = Head로 연결돼 있는 구조를 의미함

// 이렇게 구현하면 AppendNode 성능을 매우 빠르게 할 수 있음
// Reverse로 노드를 탐색하는것도 가능함




int main()
{
	int i = 0;
	int Count = 0;
	Node* List = nullptr;
	Node* NewNode = nullptr;
	Node* Current = nullptr;

	// 노드 5개 추가 
	for (int i = 0; i < 5; i++)
	{
		NewNode = CDLL_CreateNode(i);
		CDLL_AppendNode(&List, NewNode);
	}

	// 리스트 출력
	Count = CDLL_GetNodeCount(List);

	for (int i = 0; i < Count; i++)
	{
		Current = CDLL_GetNodeAt(List, i);
		cout << "List [" << i << "] : " << Current->Data << "\n";
	}

	// 리스트의 세 번째 칸 뒤에 노드 삽입
	cout << "\nInserting 3000 After [2] .. \n\n";

	Current = CDLL_GetNodeAt(List, 2);
	NewNode = CDLL_CreateNode(3000);
	CDLL_InsertAfter(Current, NewNode);

}