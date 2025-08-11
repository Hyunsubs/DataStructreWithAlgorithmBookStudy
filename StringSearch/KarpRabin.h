#pragma once
#include <string>
using namespace std;

int KarpRabin(string& Text, int Start, string& Pattern);

int Hash(string& Obj, int Size);
int ReHash(string& Obj, int Start, int Size, int HashPrev, int Coefficient);