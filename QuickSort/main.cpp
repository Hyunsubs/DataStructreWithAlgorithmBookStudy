#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

void Swap(int& A, int& B)
{
	int temp = A;
	A = B;
	B = temp;
}


int Partition(int DataSet[], int Left, int Right)
{
	int First = Left;
	int Pivot = DataSet[First]; // ���� ��Ұ� �Ǵ� ��

	++Left;

	while (Left <= Right)
	{
		while (DataSet[Left] <= Pivot && Left < Right)
			++Left;

		while (DataSet[Right] >= Pivot && Left <= Right)
			--Right;

		if (Left < Right)
		{
			Swap(DataSet[Left], DataSet[Right]);
		}
		else
		{
			break;
		}
	}

	Swap(DataSet[First], DataSet[Right]);

	return Right;
}

void QuickSort(int DataSet[], int Left, int Right)
{
	if (Left < Right)
	{
		int Index = Partition(DataSet, Left, Right);

		QuickSort(DataSet, Left, Index - 1);
		QuickSort(DataSet, Index + 1, Right);
	}
}

// ��͸� �̿��Ҷ� ���Ǵ� ������ ũ�� ������ ��뷮 �����͸� ó���Ҷ� �� ������ �������� ���� �� �ִ�.
// �̷��� �ݺ����� Ȱ���ϵ��� �ؾ��Ѵ�.
void QuickSortIterative(int DataSet[], int Left, int Right)
{
	stack<pair<int, int>> s;
	s.push({ Left, Right }); // ó���� ��ü ������ ���ÿ� ����

	while (!s.empty())
	{
		// ���ÿ��� ���� ������ ���� ������
		pair<int, int> range = s.top();
		s.pop();

		int left = range.first;
		int right = range.second;

		if (left >= right)  // ���� ũ�Ⱑ 1 �����̸� �н�
			continue;

		int pivotIndex = Partition(DataSet, left, right);

		// ������ �κ� ���� �߰� (pivotIndex+1 ~ right)
		if (pivotIndex + 1 < right)
			s.push({ pivotIndex + 1, right });

		// ���� �κ� ���� �߰� (left ~ pivotIndex-1)
		if (left < pivotIndex - 1)
			s.push({ left, pivotIndex - 1 });
	}
}


int main()
{
	int DataSet[] = { 6,4,2,3,1,5 };
	int Length = sizeof DataSet / sizeof DataSet[0];

	int i = 0;

	QuickSortIterative(DataSet, 0, Length - 1);

	for (i = 0; i < Length; i++)
	{
		cout << DataSet[i] << " ";
	}

	cout << "\n";

	return 0;
}