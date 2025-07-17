#include <iostream>
#include <list>
using namespace std;

void InsertionSort(int DataSet[], int Length)
{
	int i = 0;
	int j = 0;
	int value = 0;

	for (i = 1; i < Length; i++)
	{
		if (DataSet[i - 1] <= DataSet[i])
			continue;

		value = DataSet[i];

		for (j = 0; j < i; j++)
		{
			if (DataSet[j] > value)
			{
				// 메모리의 내용을 이동시키는 C언어 표준 함수
				// 배열같이 연속된 데이터를 옮길때 유용함
				memmove(&DataSet[j + 1], &DataSet[j], sizeof(DataSet[0]) * (i - j));
				DataSet[j] = value;
				break;
			}
		}
	}
}

// 더블 링크드 리스트를 삽입 정렬하는 함수
void InsertionSort(std::list<int>& data)
{
	if (data.empty()) return;

	// 두 번째 요소부터 시작해서,
	// 그 요소를 앞쪽 정렬된 부분에 적절히 삽입
	auto it = std::next(data.begin());
	while (it != data.end())
	{
		auto current = it;
		++it;  // 다음 원소 미리 저장 (이동 후에도 사용할 수 있게)

		// 현재 요소를 정렬된 부분(처음부터 current 직전까지)에 삽입할 위치 찾기
		auto pos = data.begin();
		while (pos != current && *pos <= *current)
			++pos;

		// current가 삽입할 위치보다 앞에 있으면, 이동시켜야 함
		if (pos != current)
		{
			data.splice(pos, data, current);
			// current 위치의 요소를 pos 위치로 이동(splice는 노드 이동, 복사 X)
		}
	}
}


int main()
{
	int DataSet[] = { 6,4,2,3,1,5 };
	list<int> DataSet2;

	DataSet2.push_back(6);
	DataSet2.push_back(4);
	DataSet2.push_back(2);
	DataSet2.push_back(3);
	DataSet2.push_back(1);
	DataSet2.push_back(5);

	int Length = sizeof DataSet / sizeof DataSet[0];
	InsertionSort(DataSet, Length);

	for (int i = 0; i < Length; i++)
	{
		cout << DataSet[i] << " ";
	}
	cout << "\n";

	InsertionSort(DataSet2);
	
	auto iter = DataSet2.begin();

	while (iter != DataSet2.end())
	{
		cout << *iter << " ";
		iter++;
	}
	cout << "\n";

	return 0;
}