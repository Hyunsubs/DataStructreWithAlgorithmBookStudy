#pragma once
#include "Graph.h"
#include <list>
#include <iostream>
using namespace std;

void TopologicalSort(Vertex* V, list<Vertex>& List);
void TS_DFS(Vertex* V, list<Vertex>& List);