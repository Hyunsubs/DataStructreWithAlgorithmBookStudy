#include "KarpRabin.h"

int KarpRabin(string& Text, int Start, string& Pattern)
{
    int i = 0;
    int j = 0;
    int Coefficient = pow(2, Pattern.size() - 1);
    int HashText = Hash(Text, Pattern.size());
    int HashPattern = Hash(Pattern, Pattern.size());

    for (i = Start; i < Text.size() - Pattern.size(); i++)
    {
        HashText = ReHash(Text, i, Pattern.size(), HashText, Coefficient);

        if (HashPattern == HashText)
        {
            for (j = 0;  j < Pattern.size(); ++j)
            {
                if (Text[i + j] != Pattern[j])
                    break;
            }

            if (j >= Pattern.size())
                return i;
        }
    }

    return -1;
}

int Hash(string& Obj, int Size)
{
    int i = 0;
    int HashValue = 0;

    for (i = 0; i < Size; i++)
    {
        HashValue = Obj[i] + (HashValue * 2);
    }
    return HashValue;
}

int ReHash(string& Obj, int Start, int Size,  int HashPrev, int Coefficient)
{
    if (Start == 0)
        return HashPrev;

    return Obj[Start + Size - 1] + ((HashPrev - Coefficient * Obj[Start - 1]) * 2);
}
