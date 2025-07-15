#include <iostream>
using namespace std;

void BubbleSort(int DataSet[], int Length)
{
	int i = 0;
	int j = 0;

	int temp = 0;
	bool flag = false;

	for (i = 0; i < Length-1; i++)
	{
		for (j = 0; j < Length - (i+1); j++)
		{
			if (DataSet[j] > DataSet[j+1])
			{
				temp = DataSet[j + 1];
				DataSet[j + 1] = DataSet[j];
				DataSet[j] = temp;
				flag = true;
			}
		}

		if (!flag)
		{
			cout << "이미 정렬돼 있음.\n";
			break;
		}
	}
}



int main()
{
	int DataSet[] = { 6,4,2,3,1,5 };
	int DataSet2[] = { 1,2,3,4,5,6,7,8,9,10 };
	int Length = sizeof DataSet / sizeof DataSet[0];
	int Length2 = sizeof DataSet2 / sizeof DataSet2[0];

	BubbleSort(DataSet, Length);

	for (int i = 0; i < Length; i++)
	{
		cout << DataSet[i] << " ";
	}
	cout << "\n";

	BubbleSort(DataSet2, Length2);

	for (int i = 0; i < Length2; i++)
	{
		cout << DataSet2[i] << " ";
	}

	cout << "\n";

	return 0;
}