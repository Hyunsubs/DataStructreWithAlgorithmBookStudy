#include <iostream>
using namespace std;

class Node
{
private:
	int Data;
	Node* NextNode;

public:
	Node()
		: Data(0)
		, NextNode(nullptr)
	{

	}

	Node(int Data)
		: Data(Data)
		, NextNode(nullptr)
	{

	}

	~Node()
	{
		if (NextNode)
		{
			NextNode = nullptr;
		}
	}

	int GetData()
	{
		return Data;
	}

	friend class LinkedQueue;
};

class LinkedQueue
{
private:
	Node* Front;
	Node* Rear;

	int Count;

public:
	LinkedQueue()
		: Front(nullptr)
		, Rear(nullptr)
		, Count(0)
	{

	}

	~LinkedQueue()
	{
		Node* Current = Front;
		while (Current != nullptr)
		{
			Node* Temp = Current;
			delete(Temp);
			Current = Current->NextNode;
		}
	}

	void Enqueue(int Data)
	{
		if (Front == nullptr)
		{
			Node* NewNode = new Node(Data);
			Front = NewNode;
			Rear = NewNode;
			Count++;
		}
		else
		{
			Node* NewNode = new Node(Data);
			Rear->NextNode = NewNode;
			Rear = NewNode;
			Count++;
		}
	}

	Node* Dequeue()
	{
		Node* FrontNode = Front;

		if (Front->NextNode == nullptr)
		{
			Front = nullptr;
			Rear = nullptr;
		}
		else
		{
			Node* TempNode = Front;
			Front = Front->NextNode;
		}
		Count--;

		return FrontNode;
	}

	int GetSize()
	{
		return Count;
	}

	bool IsEmpty()
	{
		return Front == nullptr;
	}
};

int main()
{
	LinkedQueue Queue;
	Queue.Enqueue(10);
	Queue.Enqueue(20);
	Queue.Enqueue(30);
	Queue.Enqueue(40);
	Queue.Enqueue(50);

	cout << "Queue Size : " << Queue.GetSize() << "\n";

	while (!Queue.IsEmpty())
	{
		Node* Popped = Queue.Dequeue();
		cout << "Dequeue : " << Popped->GetData() << "\n";
		delete(Popped);
	}

	return 0;
}