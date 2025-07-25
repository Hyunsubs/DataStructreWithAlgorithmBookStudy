#include "ShortestPath.h"
#include "MST.h"

void Dijkstra(Graph* G, Vertex* StartVertex, Graph* ShortestPath)
{
	int i = 0;

	PQNode StartNode = { 0, StartVertex };
	priority_queue<PQNode> pq = {};

	Vertex* CurrentVertex = nullptr;
	Edge* CurrentEdge = nullptr;

	int* Weights = (int*)malloc(sizeof(int) * G->VertexCount);
	Vertex** ShortestPathVertices = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);

	Vertex** Fringes = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);
	Vertex** Precedences = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);

	CurrentVertex = G->Vertices;
	while (CurrentVertex != nullptr)
	{

		Vertex* NewVertex = CreateVertex(CurrentVertex->Data);
		AddVertex(ShortestPath, NewVertex);

		Fringes[i] = nullptr;
		Precedences[i] = nullptr;
		ShortestPathVertices[i] = NewVertex;
		Weights[i] = MAX_WEIGHT;
		CurrentVertex = CurrentVertex->Next;
		i++;
	}

	pq.push(StartNode);

	Weights[StartVertex->Index] = 0;

	while (!pq.empty())
	{
		PQNode Popped;

		Popped = pq.top();
		pq.pop();

		CurrentVertex = Popped.V;

		Fringes[CurrentVertex->Index] = CurrentVertex;

		CurrentEdge = CurrentVertex->AdjacencyList;
		while (CurrentEdge != nullptr)
		{
			Vertex* TargetVertex = CurrentEdge->Target;

			if (Fringes[TargetVertex->Index] == nullptr && Weights[CurrentVertex->Index] + CurrentEdge->Weight < Weights[TargetVertex->Index])
			{
				PQNode NewNode = { CurrentEdge->Weight, TargetVertex };
				pq.push(NewNode);

				Precedences[TargetVertex->Index] = CurrentEdge->From;
				Weights[TargetVertex->Index] = Weights[CurrentVertex->Index] + CurrentEdge->Weight;
			}

			CurrentEdge = CurrentEdge->Next;
		}
	}

	for (i = 0; i < G->VertexCount; i++)
	{
		int FromIndex, ToIndex;

		if (Precedences[i] == nullptr)
			continue;

		FromIndex = Precedences[i]->Index;
		ToIndex = i;

		AddEdge(ShortestPathVertices[FromIndex], CreateEdge(ShortestPathVertices[FromIndex], ShortestPathVertices[ToIndex], Weights[i]));
	}

	delete(Fringes);
	delete(Precedences);
	delete(ShortestPathVertices);
	delete(Weights);


}
