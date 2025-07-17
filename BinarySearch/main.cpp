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

	while (Left <= Right) // 탐색 범위의 크기가 0이 될 때까지 while문 반복
	{
		Mid = (Left + Right) / 2; // 중앙 요소 위치 계산

		if (Target == DataSet[Mid])
			return DataSet[Mid];
		else if (Target > DataSet[Mid])
			Left = Mid + 1;
		else
			Right = Mid - 1;
	}

	cout << "탐색하고자 하는 데이터가 존재하지 않습니다.\n";

	return NULL; 
}

// 부동 소수 오차를 고려한 템플릿 특수화
template<>
float BinarySearch(vector<float>& DataSet, float Target)
{
	int Left, Right, Mid;

	Left = 0;
	Right = (int)DataSet.size() - 1;

	while (Left <= Right) // 탐색 범위의 크기가 0이 될 때까지 while문 반복
	{
		Mid = (Left + Right) / 2; // 중앙 요소 위치 계산

		if (abs(Target - DataSet[Mid]) <= KINDA_SMALL_NUMBER)
			return DataSet[Mid];
		else if (Target > DataSet[Mid])
			Left = Mid + 1;
		else
			Right = Mid - 1;
	}

	cout << "탐색하고자 하는 데이터가 존재하지 않습니다.\n";

	return numeric_limits<float>::quiet_NaN(); // 값 없음 표현에 사용되는 값

}

int main()
{



	return 0;
}