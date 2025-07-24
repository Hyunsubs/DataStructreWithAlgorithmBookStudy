#pragma once
#include <iostream>

enum VisitNode 
{
	NotVisited,
	Visited
};

typedef struct tagVertex
{
	int Data;
	bool Visited;
	int Index;

	struct tagVertex* Next;
	struct tagEdge* AdjacencyList;
} Vertex;

typedef struct tagEdge
{
	int Weight;
	struct tagEdge* Next;
	Vertex* From;
	Vertex* Target;
} Edge;

typedef struct tagGraph
{
	Vertex* Vertices;
	int VertexCount;
} Graph;

Graph* CreateGraph();
void DestroyGraph(Graph* G);

Vertex* CreateVertex(int Data);
void DestroyVertex(Vertex* V);

Edge* CreateEdge(Vertex* From, Vertex* Target, int Weight);
void DestroyEdge(Edge* E);

void AddVertex(Graph* G, Vertex* V);
void AddEdge(Vertex* V, Edge* E);
void PrintGraph(Graph* G);