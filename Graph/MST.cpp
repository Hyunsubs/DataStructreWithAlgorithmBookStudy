#include "MST.h"
#include "DisjointSet.h"

void Prim(Graph* G, Vertex* StartVertex, Graph* MST)
{
    int i = 0;

    priority_queue<PQNode> pq;

    Vertex* CurrentVertex = nullptr;
    Edge* CurrentEdge = nullptr;

    int* Weights = (int*)malloc(sizeof(int) * G->VertexCount);
    Vertex** MSTVertices = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);
    Vertex** Fringes = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);
    Vertex** Precedences = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);

    CurrentVertex = G->Vertices;
    while (CurrentVertex != nullptr)
    {
        Vertex* NewVertex = CreateVertex(CurrentVertex->Data);
        AddVertex(MST, NewVertex);

        Fringes[i] = nullptr;
        Precedences[i] = nullptr;
        MSTVertices[i] = NewVertex;
        Weights[i] = MAX_WEIGHT;
        CurrentVertex = CurrentVertex->Next;
        i++;
    }

    pq.push({ 0, StartVertex });
    Weights[StartVertex->Index] = 0;

    while (!pq.empty())
    {
        PQNode Popped = pq.top();
        pq.pop();

        CurrentVertex = Popped.V;

        if (Fringes[CurrentVertex->Index] != nullptr)
            continue; // 이미 포함된 정점은 건너뜀

        Fringes[CurrentVertex->Index] = CurrentVertex;

        CurrentEdge = CurrentVertex->AdjacencyList;
        while (CurrentEdge != nullptr)
        {
            Vertex* TargetVertex = CurrentEdge->Target;

            if (Fringes[TargetVertex->Index] == nullptr &&
                CurrentEdge->Weight < Weights[TargetVertex->Index])
            {
                pq.push({ CurrentEdge->Weight, TargetVertex });

                Precedences[TargetVertex->Index] = CurrentEdge->From;
                Weights[TargetVertex->Index] = CurrentEdge->Weight;
            }

            CurrentEdge = CurrentEdge->Next;
        }
    }

    for (int i = 0; i < G->VertexCount; i++)
    {
        int FromIndex, ToIndex;

        if (Precedences[i] == nullptr)
            continue;

        FromIndex = Precedences[i]->Index;
        ToIndex = i;

        AddEdge(MSTVertices[FromIndex], CreateEdge(MSTVertices[FromIndex], MSTVertices[ToIndex], Weights[i]));
        AddEdge(MSTVertices[ToIndex], CreateEdge(MSTVertices[ToIndex], MSTVertices[FromIndex], Weights[i]));
    }

    free(Fringes);
    free(Precedences);
    free(MSTVertices);
    free(Weights);
}

void Kruskal(Graph* G, Graph* MST)
{
    int i;
    Vertex* CurrentVertex = nullptr;
    Vertex** MSTVertices = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);

    DisjointSet** VertexSet = (DisjointSet**)malloc(sizeof(DisjointSet*) * G->VertexCount);

    priority_queue<PQNodeKruskal> pq = {};

    i = 0;
    CurrentVertex = G->Vertices;

    while (CurrentVertex != nullptr)
    {
        Edge* CurrentEdge;

        VertexSet[i] = DS_MakeSet(CurrentVertex);
        MSTVertices[i] = CreateVertex(CurrentVertex->Data);
        AddVertex(MST, MSTVertices[i]);

        CurrentEdge = CurrentVertex->AdjacencyList;
        while (CurrentEdge != nullptr)
        {
            PQNodeKruskal NewNode = { CurrentEdge->Weight, CurrentEdge };
            pq.push(NewNode);

            CurrentEdge = CurrentEdge->Next;
        }

        CurrentVertex = CurrentVertex->Next;
        i++;
    }
    
    while (!pq.empty())
    {
        Edge* CurrentEdge;
        int FromIndex;
        int ToIndex;
        PQNodeKruskal Popped;

        Popped = pq.top();
        pq.pop();
        CurrentEdge = Popped.E;

        printf("%c - %c : %d \n", CurrentEdge->From->Data, CurrentEdge->Target->Data, CurrentEdge->Weight);

        FromIndex = CurrentEdge->From->Index;
        ToIndex = CurrentEdge->Target->Index;

        if (DS_FindSet(VertexSet[FromIndex]) != DS_FindSet(VertexSet[ToIndex]))
        {
            AddEdge(MSTVertices[FromIndex], CreateEdge(MSTVertices[FromIndex], MSTVertices[ToIndex], CurrentEdge->Weight));

            AddEdge(MSTVertices[ToIndex], CreateEdge(MSTVertices[ToIndex], MSTVertices[FromIndex], CurrentEdge->Weight));

            DS_UnionSet(VertexSet[FromIndex], VertexSet[ToIndex]);
        }
    }

    for (i = 0; i < G->VertexCount; i++)
        DS_DestroySet(VertexSet[i]);

    delete(VertexSet);
    delete(MSTVertices);

}
