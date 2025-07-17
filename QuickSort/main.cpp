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
	int Pivot = DataSet[First]; // 기준 요소가 되는 값

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

// 재귀를 이용할때 사용되는 스택의 크기 때문에 대용량 데이터를 처리할땐 퀵 정렬이 유용하지 않을 수 있다.
// 이럴때 반복문을 활용하도록 해야한다.
void QuickSortIterative(int DataSet[], int Left, int Right)
{
	stack<pair<int, int>> s;
	s.push({ Left, Right }); // 처음에 전체 구간을 스택에 넣음

	while (!s.empty())
	{
		// 스택에서 현재 정렬할 구간 꺼내기
		pair<int, int> range = s.top();
		s.pop();

		int left = range.first;
		int right = range.second;

		if (left >= right)  // 구간 크기가 1 이하이면 패스
			continue;

		int pivotIndex = Partition(DataSet, left, right);

		// 오른쪽 부분 구간 추가 (pivotIndex+1 ~ right)
		if (pivotIndex + 1 < right)
			s.push({ pivotIndex + 1, right });

		// 왼쪽 부분 구간 추가 (left ~ pivotIndex-1)
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