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
				// �޸��� ������ �̵���Ű�� C��� ǥ�� �Լ�
				// �迭���� ���ӵ� �����͸� �ű涧 ������
				memmove(&DataSet[j + 1], &DataSet[j], sizeof(DataSet[0]) * (i - j));
				DataSet[j] = value;
				break;
			}
		}
	}
}

// ���� ��ũ�� ����Ʈ�� ���� �����ϴ� �Լ�
void InsertionSort(std::list<int>& data)
{
	if (data.empty()) return;

	// �� ��° ��Һ��� �����ؼ�,
	// �� ��Ҹ� ���� ���ĵ� �κп� ������ ����
	auto it = std::next(data.begin());
	while (it != data.end())
	{
		auto current = it;
		++it;  // ���� ���� �̸� ���� (�̵� �Ŀ��� ����� �� �ְ�)

		// ���� ��Ҹ� ���ĵ� �κ�(ó������ current ��������)�� ������ ��ġ ã��
		auto pos = data.begin();
		while (pos != current && *pos <= *current)
			++pos;

		// current�� ������ ��ġ���� �տ� ������, �̵����Ѿ� ��
		if (pos != current)
		{
			data.splice(pos, data, current);
			// current ��ġ�� ��Ҹ� pos ��ġ�� �̵�(splice�� ��� �̵�, ���� X)
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