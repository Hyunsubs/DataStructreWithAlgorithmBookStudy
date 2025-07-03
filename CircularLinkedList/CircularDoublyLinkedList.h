#pragma once

#include <iostream>
using namespace std;

struct Node
{
	int Data;
	Node* Prev;
	Node* Next;

	Node(int NewData)
		: Data(NewData)
		, Prev(nullptr)
		, Next(nullptr)
	{
		
	}
};

Node* CDLL_CreateNode(int Data);
void CDLL_DestoryNode(Node* Node);
void CDLL_AppendNode(Node** Head, Node* NewNode);
void CDLL_InsertAfter(Node* Current, Node* NewNode);
void RemoveNode(Node** Head, Node* Remove);
Node* CDLL_GetNodeAt(Node* Head, int Location);
int CDLL_GetNodeCount(Node* Head);
void PrintNode(Node* _Node);
