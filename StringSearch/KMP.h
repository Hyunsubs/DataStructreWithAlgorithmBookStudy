#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> MakeTable(string pattern)
{
	int patternSize = pattern.size();
	vector<int> table(patternSize, 0);
	int j = 0;
	for (int i = 1; i < patternSize; i++)
	{
		while (j > 0 && pattern[i] != pattern[j])
		{
			j = table[j - 1];
		}

		if (pattern[i] == pattern[j])
		{
			table[i] = ++j;
		}


	}
	return table;
}

void KMP(string parent, string pattern)
{
	vector<int> table = MakeTable(pattern);
	int parentSize = parent.size();
	int patternSize = pattern.size();
	int j = 0;
	for (int i = 0; i < ; i++)
	{
		while (j > 0 && parent[i] != pattern[j])
		{
			j = table[j - 1];
		}
		
		if (parent[i] == pattern[j])
		{
			if (j == patternSize - 1)
			{
				cout << i - patternSize + 2 << "번째에서 찾았습니다.\n";
				j = table[j];
			}
			else
			{
				j++;
			}
		}
	}
}
