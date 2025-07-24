#include "TopologicalSort.h"

void TopologicalSort(Vertex* V, list<Vertex>& List)
{
	while (V != nullptr && V->Visited == NotVisited)
	{
		TS_DFS(V, List);
		V = V->Next;
	}
}

void TS_DFS(Vertex* V, list<Vertex>& List)
{
	Vertex* NewHead = nullptr;
	Edge* E = nullptr;

	V->Visited = Visited;

	E = V->AdjacencyList;

	while (E != nullptr)
	{
		if (E->Target != nullptr && E->Target->Visited == NotVisited)
			TS_DFS(E->Target, List);

		E = E->Next;
	}

	printf("%c\n", V->Data);

	NewHead = V;
	List.push_front(*NewHead);
}
