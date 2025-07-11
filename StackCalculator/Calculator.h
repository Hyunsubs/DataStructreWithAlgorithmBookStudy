#pragma once

#include <iostream>

enum SYMBOL
{
	LEFT_PARENTHESIS = '(',
	RIGHT_PARENTHESIS = ')',
	PLUS = '+',
	MINUS = '-',
	MULTIPLY = '*',
	DIVIDE = '/',
	SPACE = ' ',
	OPERAND
};

int IsNumber(char Cipher);
unsigned int GetNextToken(char* Expression, char* Token, int* Type);
int IsPrior(char OperatorInStack, char OperatorInToken);
void GetPostfix(char* InfixExpression, char* PostfixExpression);
double Calculate(char* PostfixExpression);

