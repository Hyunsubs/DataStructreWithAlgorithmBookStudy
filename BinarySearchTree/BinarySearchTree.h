#pragma once

#include <iostream>
using namespace std;

struct BSTNode
{
	BSTNode* Left;
	BSTNode* Right;

	int Data;
};


BSTNode* BST_CreateNode(int NewData);
void BST_DestroyNode(BSTNode* Node);
void BST_DestroyTree(BSTNode* Tree);

BSTNode* BST_SearchNode(BSTNode* Tree, int Target);
BSTNode* BST_SearchMinNode(BSTNode* Tree);
void BST_InsertNode(BSTNode* Tree, BSTNode* Child);
BSTNode* BST_RemoveNode(BSTNode* Tree, BSTNode* Parent, int Target);
void BST_InorderPrintTree(BSTNode* Node);

