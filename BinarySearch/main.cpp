#include <iostream>
#include <vector>
#include <limits>
using namespace std;

#define KINDA_SMALL_NUMBER 0.001f

template<typename T>
T BinarySearch(vector<T>& DataSet, T Target)
{
	int Left, Right, Mid;

	Left = 0;
	Right = (int)DataSet.size() - 1;

	while (Left <= Right) // Ž�� ������ ũ�Ⱑ 0�� �� ������ while�� �ݺ�
	{
		Mid = (Left + Right) / 2; // �߾� ��� ��ġ ���

		if (Target == DataSet[Mid])
			return DataSet[Mid];
		else if (Target > DataSet[Mid])
			Left = Mid + 1;
		else
			Right = Mid - 1;
	}

	cout << "Ž���ϰ��� �ϴ� �����Ͱ� �������� �ʽ��ϴ�.\n";

	return NULL; 
}

// �ε� �Ҽ� ������ ����� ���ø� Ư��ȭ
template<>
float BinarySearch(vector<float>& DataSet, float Target)
{
	int Left, Right, Mid;

	Left = 0;
	Right = (int)DataSet.size() - 1;

	while (Left <= Right) // Ž�� ������ ũ�Ⱑ 0�� �� ������ while�� �ݺ�
	{
		Mid = (Left + Right) / 2; // �߾� ��� ��ġ ���

		if (abs(Target - DataSet[Mid]) <= KINDA_SMALL_NUMBER)
			return DataSet[Mid];
		else if (Target > DataSet[Mid])
			Left = Mid + 1;
		else
			Right = Mid - 1;
	}

	cout << "Ž���ϰ��� �ϴ� �����Ͱ� �������� �ʽ��ϴ�.\n";

	return numeric_limits<float>::quiet_NaN(); // �� ���� ǥ���� ���Ǵ� ��

}

int main()
{



	return 0;
}