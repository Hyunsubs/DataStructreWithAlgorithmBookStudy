#pragma once
#include <iostream>
#include <memory>

struct Node
{
	int Data;
};

struct Heap
{
	Node* Nodes;
	int Capacity;
	int UsedSize;
};

Heap* HEAP_Create(int InitialSize);
void HEAP_Destroy(Heap* H);
void HEAP_Insert(Heap* H, int NewData);
void HEAP_DeleteMin(Heap* H, Node* Root);
int HEAP_GetParent(int Index);
int HEAP_GetLeftChild(int Index);
void HEAP_SwapNodes(Heap* H, int Index1, int Index2);
void HEAP_PrintNodes(Heap* H);

