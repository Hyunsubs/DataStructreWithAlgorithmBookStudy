#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Calculator.h"
using namespace std;


int main()
{
	char InfixExpression[100];
	char PostfixExpression[100];

	double Result = 0.0;

	memset(InfixExpression, 0, sizeof(InfixExpression));
	memset(PostfixExpression, 0, sizeof(PostfixExpression));

	cin >> InfixExpression;
	GetPostfix(InfixExpression, PostfixExpression);

	Result = Calculate(PostfixExpression);

	cout << Result;

	return 0;
}