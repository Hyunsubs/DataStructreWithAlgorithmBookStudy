#include <iostream>
#include "KarpRabin.h"

using namespace std;

int main()
{
	string Text;
	string Pattern;

	cin >> Text;
	cin >> Pattern;

	int Position = KarpRabin(Text, 0, Pattern);

	cout << "전체 텍스트 : " << Text << "\n";
	cout << "찾는 패턴 : " << Pattern << "\n";

	if (Position >= 0)
	{
		cout << "찾는 패턴이 " << Position + 1 << "번째 위치에 존재합니다.\n";
	}

	else
	{
		cout << "찾는 패턴이 존재하지 않습니다.\n";
	}

	return 0;
}