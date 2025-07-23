#include "Heap.h"

Heap* HEAP_Create(int InitialSize)
{
    Heap* NewHeap = new Heap;
    NewHeap->Capacity = InitialSize;
    NewHeap->UsedSize = 0;
    NewHeap->Nodes = new Node[NewHeap->Capacity];

    std::cout << "size : " << sizeof(Node) << "\n";
    return NewHeap;
}

void HEAP_Destroy(Heap* H)
{
    delete(H->Nodes);
    delete(H);
}

void HEAP_Insert(Heap* H, int NewData)
{
    int CurrentPosition = H->UsedSize;
    int ParentPosition = HEAP_GetParent(CurrentPosition);


    if (H->UsedSize == H->Capacity)
    {
        H->Capacity *= 2;
        H->Nodes = (Node*)realloc(H->Nodes, sizeof(Node) * H->Capacity);
    }

    H->Nodes[CurrentPosition].Data = NewData;
    
    // 후속 처리
    while (CurrentPosition > 0 && H->Nodes[CurrentPosition].Data < H->Nodes[ParentPosition].Data)
    {
        HEAP_SwapNodes(H, CurrentPosition, ParentPosition);

        CurrentPosition = ParentPosition;
        ParentPosition = HEAP_GetParent(CurrentPosition);
    }

    H->UsedSize++;
}

void HEAP_DeleteMin(Heap* H, Node* Root)
{
    int ParentPosition = 0;
    int LeftPosition = 0;
    int RightPosition = 0;

    memcpy(Root, &H->Nodes[0], sizeof(Node));
    memset(&H->Nodes[0], 0, sizeof(Node));

    H->UsedSize--;
    HEAP_SwapNodes(H, 0, H->UsedSize);

    LeftPosition = HEAP_GetLeftChild(0);
    RightPosition = LeftPosition + 1;

    while (true)
    {
        int SelectedChild = 0;

        if (LeftPosition >= H->UsedSize)
            break;

        if (RightPosition >= H->UsedSize)
        {
            SelectedChild = LeftPosition;
        }
        else
        {
            if (H->Nodes[LeftPosition].Data > H->Nodes[RightPosition].Data)
                SelectedChild = RightPosition;
            else
                SelectedChild = LeftPosition;
        }

        if (H->Nodes[SelectedChild].Data < H->Nodes[ParentPosition].Data)
        {
            HEAP_SwapNodes(H, ParentPosition, SelectedChild);
            ParentPosition = SelectedChild;
        }
        else
            break;

        LeftPosition = HEAP_GetLeftChild(ParentPosition);
        RightPosition = LeftPosition + 1;
    }

    if (H->UsedSize < (H->Capacity / 2))
    {
        H->Capacity /= 2;
        H->Nodes = (Node*)realloc(H->Nodes, sizeof(Node) * H->Capacity);
    }
}

int HEAP_GetParent(int Index)
{
    return (int)((Index - 1) / 2);
}

int HEAP_GetLeftChild(int Index)
{
    return (2 * Index) + 1;
}

void HEAP_SwapNodes(Heap* H, int Index1, int Index2)
{
    int CopySize = sizeof(Node);
    Node* Temp = new Node;

    memcpy(Temp, &H->Nodes[Index1], CopySize);
    memcpy(&H->Nodes[Index1], &H->Nodes[Index2], CopySize);
    memcpy(&H->Nodes[Index2], Temp, CopySize);

    delete Temp;
}

void HEAP_PrintNodes(Heap* H)
{
    int i = 0;
    for (i = 0; i < H->UsedSize; i++)
    {
        std::cout << H->Nodes[i].Data << " ";
    }
    std::cout << "\n";
}
