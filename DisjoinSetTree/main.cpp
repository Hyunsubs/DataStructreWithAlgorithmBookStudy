#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <stdlib.h>
#include <crtdbg.h>
using namespace std;

// 분리 집합
// 노드가 자식을 아는것이 아닌 부모를 아는 형태로 구현함
class Node
{
public:
	Node* Parent;
	int* Data; // 모든 종류의 데이터를 담기 위한 void*

	Node(int* Data)
		: Data(Data)
		, Parent(nullptr)
	{

	}

	~Node()
	{
		if (Data)
		{
			delete Data;
		}
	}
};

// 집합 탐색 연산
// 부모가 없는 노드를 계속 타고 올라가면 그것이 집합을 대표하는 노드가 됨
Node* FindSet(Node* Set)
{
	while (Set->Parent != nullptr)
	{
		Set = Set->Parent;
	}

	return Set;
}

// 합집합 연산
// 하나의 집합을 기존에 있던 집합에 넣기
// 넣으려는 집합의 부모를 넣는곳의 부모로 설정하면 됨
void UnionSet(Node* Set1, Node* Set2)
{
	Set2 = FindSet(Set2);
	Set2->Parent = Set1;
}



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int* a = new int(1);
	int* b = new int(2);
	int* c = new int(3);
	int* d = new int(4);
	Node* Set1 = new Node(a);
	Node* Set2 = new Node(b);
	Node* Set3 = new Node(c);
	Node* Set4 = new Node(d);


	UnionSet(Set1, Set3);
	UnionSet(Set2, Set4);

	delete Set1;
	delete Set2;



	return 0;
}