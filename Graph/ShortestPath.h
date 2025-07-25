#pragma once
#include "Graph.h"
#include <queue>
using namespace std;

#define MAX_WEIGHT 36267

void Dijkstra(Graph* G, Vertex* StartVertex, Graph* ShortestPath);
