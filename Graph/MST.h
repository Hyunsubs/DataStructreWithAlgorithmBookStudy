#pragma once
#include <iostream>
#include <queue>
#include "Graph.h"
using namespace std;

#define MAX_WEIGHT 36267

struct PQNode {
	int Weight;
	Vertex* V;

	bool operator<(const PQNode& other) const {
		return Weight > other.Weight; // 최소 힙처럼 동작
	}
};

struct PQNodeKruskal
{
	int Weight;
	Edge* E;

	bool operator<(const PQNodeKruskal& other) const {
		return Weight > other.Weight; // 최소 힙처럼 동작
	}
};


void Prim(Graph* G, Vertex* StartVertex, Graph* MST);
void Kruskal(Graph* G, Graph* MST);
