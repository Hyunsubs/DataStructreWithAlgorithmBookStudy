#include "Graph.h"

Graph* CreateGraph()
{
    Graph* graph = new Graph;
    graph->Vertices = nullptr;
    graph->VertexCount = 0;
    
    return graph;
}

void DestroyGraph(Graph* G)
{
    while (G->Vertices != nullptr)
    {
        Vertex* Vertices = G->Vertices->Next;
        DestroyVertex(G->Vertices);
        G->Vertices = Vertices;
    }

    delete(G);
}

Vertex* CreateVertex(int Data)
{
    Vertex* V = new Vertex;
    V->Data = Data;
    V->Next = nullptr;
    V->AdjacencyList = nullptr;
    V->Visited = NotVisited;
    V->Index = 01;

    return V;

}

void DestroyVertex(Vertex* V)
{
    while (V->AdjacencyList != nullptr)
    {
        Edge* Edge = V->AdjacencyList->Next;

        DestroyEdge(V->AdjacencyList);

        V->AdjacencyList = Edge;
    }

    delete V;
}

Edge* CreateEdge(Vertex* From, Vertex* Target, int Weight)
{
    Edge* E = new Edge;
    E->From = From;
    E->Target = Target;
    E->Next = nullptr;
    E->Weight = Weight;

    return E;
}

void DestroyEdge(Edge* E)
{
    delete(E);
}

void AddVertex(Graph* G, Vertex* V)
{
    Vertex* VertexList = G->Vertices;

    if (VertexList == nullptr)
    {
        G->Vertices = V;
    }

    else
    {
        while (VertexList->Next != nullptr)
        {
            VertexList = VertexList->Next;
        }

        VertexList->Next = V;
    }

    V->Index = G->VertexCount++;
}

void AddEdge(Vertex* V, Edge* E)
{
    if (V->AdjacencyList == nullptr)
    {
        V->AdjacencyList = E;
    }

    else
    {
        Edge* AdjacencyList = V->AdjacencyList;

        while (AdjacencyList->Next != nullptr)
        {
            AdjacencyList = AdjacencyList->Next;
        }

        AdjacencyList->Next = E;
    }
}

void PrintGraph(Graph* G)
{
    Vertex* V = nullptr;
    Edge* E = nullptr;

    if ((V = G->Vertices) == nullptr)
        return;

    while (V != nullptr)
    {
        printf("%c : ", V->Data);

        if ((E = V->AdjacencyList) == nullptr)
        {
            V = V->Next;
            std::cout << "\n";
            continue;
        }

        while (E != nullptr)
        {
            printf("%c[%d] ", E->Target->Data, E->Weight);
            E = E->Next;
        }

        std::cout << "\n";

        V = V->Next;
    }

    std::cout << "\n";
}
