#include <iostream>
using namespace std;

class Node
{
private:
	int Data;

	friend class CircularQueue;

public:
	Node()
		: Data(0)
	{

	}

	Node(int Data)
		: Data(Data)
	{

	}
};

class CircularQueue
{
	int Capacity;
	int Front;
	int Rear;

	Node* Nodes;

public:
	CircularQueue(int Capacity)
		: Capacity(Capacity)
		, Front(0)
		, Rear(0)
		, Nodes(nullptr)
	{
		Nodes = new Node[Capacity + 1];
	}

	~CircularQueue()
	{
		if (Nodes)
		{
			delete[] Nodes;
			Nodes = nullptr;
		}
	}

public:
	void Enqueue(int _Data)
	{
		int Position = 0;
		if (Rear == Capacity)
		{
			// 배열 끝에 도달한 경우 다시 위치를 0으로 조정
			Position = Rear;
			Rear = 0;
		}
		else
		{
			Position = Rear++;
		}
		Nodes[Position].Data = _Data;
	}

	int Dequeue()
	{
		int Position = Front;
		if (Front == Capacity)
		{
			Front = 0;
		}
		else
		{
			Front++;
		}

		return Nodes[Position].Data;
	}

	bool IsEmpty()
	{
		return Front == Rear;
	}

	bool IsFull()
	{
		if (Front < Rear)
			return  (Rear - Front) == Capacity;
		else
			return Rear + 1 == Front;
	}

	int GetSize()
	{
		if (Front <= Rear)
		{
			return Rear - Front;
		}
		else
		{
			return Rear + (Capacity - Front) + 1;
		}
	}

	int GetCapacity()
	{
		return Capacity;
	}
};


int main()
{
	CircularQueue Queue(10);

	Queue.Enqueue(15);
	Queue.Enqueue(20);
	Queue.Enqueue(25);

	Queue.GetSize();

	for (int i = 0; i < 3; i++)
	{
		cout << "Dequeue: " << Queue.Dequeue() << "\n";
	}
	int i = 0;
	while (!Queue.IsFull())
	{
		Queue.Enqueue(i);
		i++;
	}

	cout << "Capacity : " << Queue.GetCapacity() << " Size : " << Queue.GetSize() << "\n";

	while (!Queue.IsEmpty())
	{
		cout << "Dequeue: " << Queue.Dequeue() << "\n";
	}

	return 0;
}